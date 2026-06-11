#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	if ((n&-n)==n) kill("No")
	cout<<"Yes\n";
	cout<<1<<' '<<2<<'\n';
	cout<<2<<' '<<3<<'\n';
	cout<<3<<' '<<1+n<<'\n';
	cout<<1+n<<' '<<2+n<<'\n';
	cout<<2+n<<' '<<3+n<<'\n';
	for (int i=5; i<=n; i+=2){
		cout<<"1 "<<i-1<<'\n';
		cout<<"1 "<<i<<'\n';
		cout<<i-1<<' '<<i+n<<'\n';
		cout<<i<<' '<<i-1+n<<'\n';
	}
	if (n%2==0){
		int lb=(n&-n);
		cout<<lb<<' '<<n+n<<'\n';
		cout<<(n^lb^1)<<' '<<n<<'\n';
		
	}
	
	return 0;
}
