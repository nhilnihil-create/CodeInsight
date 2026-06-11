#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
int n;
double ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	vector<int> x(n),y(n);
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	int p[10];
	for(int i=0;i<n;i++) p[i]=i;
	do{
		double cur=0;
		for(int i=0;i+1<n;i++){
			double a=(double)((x[p[i]]-x[p[i+1]])*(x[p[i]]-x[p[i+1]])),b=(double)((y[p[i]]-y[p[i+1]])*(y[p[i]]-y[p[i+1]]));
			cur+=(sqrt(a+b)); 
		}
		ans+=cur;
	}while(next_permutation(p,p+n));
	double r=1;
	for(int i=2;i<=n;i++) r*=(double)(i);
	cout<<fixed<<setprecision(10)<<ans/r;
	re 0;
}