#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int n, k; cin >> n >> k;
    int r, s, p; cin >> r >> s >> p;
    string t; cin >> t;

    ll ans = 0;
    V<char> memo(n);
    for(int i = 0; i < n; i++){
        if(t[i] == 'r'){
            if(i - k < 0 || (0 <= i - k && memo[i - k] != 'p')){
                ans += p;
                memo[i] = 'p';
            }else if(n <= i + k || (i + k < n && t[i + k] != 's')){
                memo[i] = 'r';
            }else{
                memo[i] = 's';
            }
        }
        if(t[i] == 's'){
            if(i - k < 0 || (0 <= i - k && memo[i - k] != 'r')){
                ans += r;
                memo[i] = 'r';
            }else if(n <= i + k || (i + k < n && t[i + k] != 'p')){
                memo[i] = 's';
            }else{
                memo[i] = 'p';
            }
        }
        if(t[i] == 'p'){
            if(i - k < 0 || (0 <= i - k && memo[i - k] != 's')){
                ans += s;
                memo[i] = 's';
            }else if(n <= i + k || (i + k < n && t[i + k] != 'r')){
                memo[i] = 'p';
            }else{
                memo[i] = 'r';
            }
        }
    }
    cout << ans << endl;

    return 0;
}
