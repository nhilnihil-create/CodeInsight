#include <bits/stdc++.h>
#define db double
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ld long double
#define maxn 5005
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define vv(z,a,b) vector<vector<int>>z(a,vector<int>(b))
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(c) begin(c),end(c)
#define pp pair<int,int>
#define fix(n) fixed << setprecision(n)
#define gmax(a,b) __gcd(a,b)
#define gmin(a,b) a/__gcd(a,b)*b
using namespace std;


int main(){

int n,m,k;
cin>>n>>m>>k;
vll a(n+1);
vll b(m+1);
rep(i,n+1){
ll an=0;

if(i==0)a.at(i)=0;
else {
cin>>an;
a.at(i)=a.at(i-1)+an;
}
}
rep(i,m+1){
int an=0;
if(i==0)b.at(i)=0;
else {
cin>>an;
b.at(i)=b.at(i-1)+an;
}
}
ll sum=0;
ll ans=0;
int ko=0;
rep(i,n+1){ 
	for(int j=m;j>=0;--j){
		sum=a.at(i)+b.at(j);
		if(sum<=k){
			ll anti =i+j;
			ans=max(ans,anti);
			m=j;
			break;
		}
		
	}
}

cout<<ans<<endl;

return 0;
}