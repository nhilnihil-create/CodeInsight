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
int N;
ll K, A[200010], F[200010];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
		cin >> F[i];
	sort(A, A + N);
	sort(F, F + N);
	reverse(F, F + N);
	ll l = 0, r = A[N - 1] * F[0], ans;
	while (l <= r){
		ll m = l + r >> 1;
		ll cnt = 0;
		for (int i = 0; i < N; ++i){
			if (A[i] * F[i] > m){
				cnt += A[i] - (m / F[i]);
			}
		}
		if (cnt > K) l = m + 1;
		else { ans = m; r = m - 1; }
	}
	cout << ans;
	return 0;
}
