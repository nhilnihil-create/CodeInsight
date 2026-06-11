#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

map<ll, ll> prime_factor(ll N) {
    map<ll, ll> prime;
    for (ll i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            prime[i]++;
            N /= i;
        }
    }

    if (N != 1) prime[N] = 1;
    return prime;
}
int main()
{
    ll A, B;
    cin >> A >> B;

    map<ll, ll> mpA = prime_factor(A);
    map<ll, ll> mpB = prime_factor(B);

    int ans = 1;
    for (auto itr : mpA) {
        if (mpB.count(itr.first)) ans++;
    }

    cout << ans << endl;
    return 0;
}