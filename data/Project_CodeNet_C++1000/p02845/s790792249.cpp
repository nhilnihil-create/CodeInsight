#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979323846264338
#define pb push_back
#define mp make_pair
#define inf 10000
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;

ll divisor=1000000007;

int main(){
	int n;
	cin>>n;
	int a[n];
	rep(i,n)cin>>a[i];
	int x[3]={};
	ll ans=1;
	rep(i,n){
		int count=0;
		rep(j,3){
			if(a[i]==x[j])count++;
		}
		ans*=count;
		ans%=divisor;
		rep(j,3){
			if(a[i]==x[j]){
				x[j]++;
				break;
			}
		}
	}
	puts(ans);
	
}
