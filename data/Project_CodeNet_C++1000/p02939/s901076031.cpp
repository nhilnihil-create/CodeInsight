#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
using Graph = V<V<int>>;
const int MOD =  1000000007;
const ll INF = 1LL << 60;


int main() {
    string s; cin >> s;
    int n = s.size();

    int ans = 1;
    bool flag = false;
    for(int i = 1; i < n; i++){
        if(flag) {
            ans++;
            flag = false;
        }else if(s[i - 1] != s[i]) {
            ans++;
        }else{
            if(i + 1 < n) {
                i++;
                flag = true;
                ans++;
            }
        }
    }
    cout << ans << endl;


    return 0;
}
