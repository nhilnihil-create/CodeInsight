#include <bits/stdc++.h>
#define double long double
#define int long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define frr(i,n) for(int i=0;i<n;i++)
#define td(v) v.begin(),v.end()
//#define M   1000000007 // 1e9 + 7
#define MAXN 100100
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<int,double> pdd;
inline int mod(int n, int m){int ret = n%m; if(ret < 0) ret += m; return ret;}
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }    else return mod(k*k,m);
}
map<string,int> M;
int t[100];

int32_t main(){
	fastio;
	int n;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s>>t[i];
		M[s] = i; 
	}
	cin>>s;
	int res=0;
	for(int j=M[s]+1;j<=n;j++){
		res+=t[j];
	}
	cout<<res<<endl;
	// Math -> gcd it all
	//did you check N=1? Did you mix up N,M?
}