#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000009
using namespace std;
int main(){
	int n;
	cin>>n;
	vector< pair< double, pair<double,double> > >eng;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if( (x!=0) || (y!=0) ) eng.pb( mp( 0.0, mp(x*1.0,y*1.0) ) );
	}
	int sz = eng.size();
	for(int i=0;i<sz;i++){
		double cx = eng[i].second.first;
		double cy = eng[i].second.second;
		eng[i].first = atan2(cy,cx);
	}
	sort(eng.begin(),eng.end());
	for(int i=0;i<sz;i++){
		eng.pb( eng[i] );
	}
	double ans = 0.0;
	for(int i=0;i<sz;i++){
		double sux = 0.0, suy = 0.0;
		for(int j=i;j<i+sz;j++){
			sux += eng[j].second.first;
			suy += eng[j].second.second;
			double dis = sux*sux + suy*suy;
			if(dis>ans)ans = dis;
		}
	}
	cout<<setprecision(12)<<sqrt(ans)<<endl;
	return 0;
}