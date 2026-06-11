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
    string s; cin >> s;
    ll k; cin >> k;

    int n = s.size();
    bool flag = true;
    ll sum = 0;
    ll cnt = 1, fcnt = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]) cnt++;
        else{
            if(flag){
                fcnt = cnt;
                flag = false;
            }else{
                sum += cnt / 2;
            }
            cnt = 1;
        }
    }

    ll sum2 = 0;
    ll ecnt = 0;
    ll bcnt = 0;
    if(s[0] == s[n - 1]){
        sum2 = (fcnt + cnt) / 2;
        bcnt = fcnt / 2;
        ecnt = cnt / 2;
    }else{
        sum += fcnt / 2;
        sum += cnt / 2;
    }

    if(n == cnt) cout << cnt * k / 2 << endl;
    else cout << sum * k + sum2 * (k - 1) + bcnt + ecnt << endl;


    return 0;
}
