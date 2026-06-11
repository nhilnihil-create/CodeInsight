#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define loop(k) rep(author_is_masa,k)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/
int modpow(int x,int n){
	int res=1;
	while(n>0){
		if(n&1) res=(res*x)%MOD;
		 x=(x*x)%MOD;
		 n>>=1;
	 }
	 return res;
}
int ncr(int n,int r){
	int res=1,fact=1;
	FOR(i,1,r) fact=(fact*i)%MOD;
	rep(i,r) res=(res*(n-i))%MOD;
	res=(res*modpow(fact,MOD-2))%MOD;
	return res;
}
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		if(n-k-i+1<0){
			cout<<0<<endl;
			continue;
		}

		cout<<ncr(n-k+1,i)*ncr(k-1,i-1)%MOD<<endl;
	}

	return 0;
}

