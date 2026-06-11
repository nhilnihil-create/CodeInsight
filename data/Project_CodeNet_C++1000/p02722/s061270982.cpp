#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

ll N; cin >> N;
ll cnt = 0;
set<ll> st; // N-1の約数(注：1を含む)
for(ll i = 1; i * i <= N-1; i++) {
    if((N-1) % i == 0) {
        st.insert(i);
        st.insert((N-1)/i);
    }
}
cnt += SZ(st) - 1;
for(ll i = 2; i * i <= N; i++) {
    if(N % i != 0) continue;
    if(i * i == N) {
        cnt++;
        continue;
    }
    ll j = N / i;
    ll cur = N;
    while(cur % i == 0) {
        cur /= i;
    }
    if(cur % i == 1) cnt++;
    cur = N;
    while(cur % j == 0) {
        cur /= j;
    }
    if(cur % j == 1) cnt++;
}
cnt++; // K = N
cout << cnt << endl;
return 0;
}