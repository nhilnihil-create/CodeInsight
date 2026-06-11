#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int main(){
    const int mod = 1e9 + 7;
    int n;
    cin >> n;
    ll a;
    ll res = 1;
    ll d[3] = {};
    for (int i = 0; i < n; ++i) {
        cin >> a;
        int tmp = 0;
        for (int j = 0; j < 3; ++j) {
            if(d[j] == a) tmp++;
        }
        if(!tmp){
            cout << 0 << endl;
            return 0;
        }
        res *= tmp;
        res %= mod;
        for (int j = 0; j < 3; ++j) {
            if(d[j] == a){
                d[j]++;
                break;
            }
        }
    }
    cout << res << endl;
}