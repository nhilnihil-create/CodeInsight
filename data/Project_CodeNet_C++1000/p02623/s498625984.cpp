#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define present(t, x) (t.find(x) != t.end())
#define sz(a) int((a).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;
const int INF = (int) 1e9+1;
inline ll gcd(ll a,ll b){ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,m,k;

void inp(){
	cin>>n>>m>>k;
	int a[n],b[m],ans=0,j=0;
	ll suma=0,sumb=0;
	FOR(i,0,n){
		cin>>a[i];
		suma+=a[i];
	}
	FOR(i,0,m)
		cin>>b[i];
	FORd(i,n+1,0){
		if(i<n)
			suma-=a[i];
		if(suma<=k){
			while(j<m&&suma+b[j]+sumb<=k){
				sumb+=b[j];
				j++;
			}
			ans=max(ans,i+j);
		}
	}
	cout<<ans<<endl;
}

int main(){
	//cout<<INT_MAX<<endl;
	inp();
	return 0;
}
