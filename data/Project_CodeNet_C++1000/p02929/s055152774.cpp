#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(ll i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
typedef tuple<ll,ll,ll> Tu;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[8]={0,1,0,-1,1,1,-1,-1},mdy[8]={-1,0,1,0,1,-1,1,-1};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int n;
string s;
bool loor[200100];
int co=0;
int main(){
	cin>>n;
	cin>>s;
	if(s[0]=='W'||s[2*n-1]=='W'){
		cout<<0<<endl;
		return 0;
	}
	loor[0]=false;
	co--;
	FOR(i,1,2*n){
		if(s[i-1]==s[i]){
			loor[i]=!loor[i-1];
		}else{
			loor[i]=loor[i-1];
		}
		if(loor[i])co++;
		else co--;
	}
	if(co!=0){
		cout<<0<<endl;
		return 0;
	}
	ll ans=1;
	ll lr_count=0;
	REP(i,2*n){
		if(loor[i]==0){
			lr_count++;
		}else{
			ans*=lr_count;
			ans%=MOD;
			lr_count--;
			if(lr_count<0){
				cout<<0<<endl;
				return 0;
			}
		}
	}
	FOR(i,1,n+1){
		ans*=i;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}