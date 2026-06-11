#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int x;
    cin >> x;
    vector<bool> prime(1000000, true);
    for (int i = 2; i < 1000000; ++i) {
        if (!prime[i]) continue;

        for (int j = 2 * i; j < 1000000; j += i) {
            prime[j] = false;
        }
    }

    for (int i = x; i < 1000000; ++i) {
        if (prime[i]){
            cout << i << endl;
            return 0;
        }
    }
}