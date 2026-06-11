#pragma GCC optimize("Ofast",3,"inline")
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define m_p make_pair
#define y1 ygftgfgcdtfgxffgx
#define y2 yfdsesgvtyghftfvv
#define x1 xvyr6cf6fgcfgf676
#define x2 xcr6rfc5r66y6r6fr
#define up_bound upper_bound
#define low_bound lower_bound
#define next_per next_permutation
#define pb push_back
#define i_to_s to_string
typedef priority_queue<int> p_queue;
typedef priority_queue<int, vector<int>, greater<int> > min_p_queue;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int mon[20]={31,28,31,30,31,30,31,31,30,31,30,31};
ll gcd(ll x,ll y){return ((y==0)?x:gcd(y,x%y));}
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
#define rep(i, n) for (int i = 0; i < (n); i++)
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	while (k--) {
		vector<ll> b(n + 1);
	    rep(i, n) b[max(0LL, i - a[i])]++, b[min(i + a[i] + 1, n)]--;
	    rep(i, n ) b[i + 1] += b[i];
	    b.pop_back();
	    if (a == b) break;
	    a = b;
	}
	rep(i,n) cout << a[i] << ' ';
	return 0;
}

