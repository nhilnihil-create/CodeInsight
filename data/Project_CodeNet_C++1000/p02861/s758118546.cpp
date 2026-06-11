#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()
#define fx(x) fixed<<setprecision(x)

int main(){
	int n; cin>>n;
	vector<pair<int,int>> vp(n);
	rep(i,n) cin>>vp[i].first>>vp[i].second;
	sort(all(vp));
	
	double ans=0; double cnt=0;
	do{
		cnt++;
		int a,b; double dis;
		for(int i=0; i<n-1; i++){
			a=vp[i].first-vp[i+1].first;
			b=vp[i].second-vp[i+1].second;
			dis+=sqrt(a*a+b*b);
		}
		ans+=dis;
	}while(next_permutation(vp.begin(),vp.end()));
	cout<<fx(10)<<ans/cnt<<endl;
}