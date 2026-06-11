#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;
const ll INF = 1LL << 60;

int main() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for(int i = 0; i < 1000; i++){
        string p;
        if(i < 10) p = "00" + to_string(i);
        else if(i < 100) p = "0" + to_string(i);
        else p = to_string(i);
        int k = 0;
        for(int j = 0; j < n; j++){
            if(p[k] == s[j]) k++;
            if(k == 3) break;
        }
        if(k == 3) ans++;
    }
    cout << ans << endl;

    return 0;
}
