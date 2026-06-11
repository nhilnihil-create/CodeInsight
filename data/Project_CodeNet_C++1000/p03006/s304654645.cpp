#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define INF      (int)1e9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef pair<int,int> pii;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
template<class Type> void join(const Type& a){int t=0;for(auto elem:a){if(t)cout<<' ';cout<<elem;++t;}cout<<endl;}

int main(){
	int n;
	cin>>n;
	
	vector<pii > p(n);
	REP(i,n){
		int x,y;
		cin>>x>>y;
		p[i]=make_pair(x,y);
	}
	sort(ALL(p));
	
	map<pii,int> mp;
	REP(i,n-1){
		for(int j=i+1;j<n;++j){
			int dx=p[j].first-p[i].first;
			int dy=p[j].second-p[i].second;
			mp[make_pair(dx,dy)]++;
		}
	}
	
	int mxm=0;
	for(auto elem:mp){
		mxm=max(mxm,elem.second);
	}
	
	cout<<n-mxm<<endl;
}