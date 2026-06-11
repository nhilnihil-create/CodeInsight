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

int top(int n){
    while(n >= 10){
        n /= 10;
    }
    return n;
}

int main(){
    int n;
    cin >> n;

    map<pii, int> mp;
    for (int i = 1; i <= n; ++i) {
        mp[pii(top(i), i%10)]++;
    }

    ll res = 0;
    for (auto &x : mp){
        int a = x.first.first;
        int b = x.first.second;
        if (a == b){
            res += x.second * x.second;
        }
        else{
            if (mp.count(pii(b, a)) > 0){
                res += x.second * mp[pii(b, a)];
            }
        }
    }
    cout << res << endl;
}

