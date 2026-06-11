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
bool isprime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}

signed main(){
	int a,b;
	cin>>a>>b;
	int g=gcd(a,b);
	
	vi yaku;
	for(int i=1;i*i<=g;i++){
		if(g%i==0){
			yaku.pb(i);
			if(i*i!=g) yaku.pb(g/i);
		}
	}
	sort(all(yaku));


	// cout<<"g="<<g<<endl;
	int ans=0;
	for(auto p:yaku){
		if(p==1||isprime(p)){
			ans++;
			// cout<<p<<endl;
		}
	}
	cout<<ans<<endl;



	return 0;
}

