#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;
const int INT_INF = 1e9;
const ll INF = 1LL << 30;
const ll MOD = 1e9 + 7;


int main() {
    string s; cin >> s;
    int n = s.size();
    V<int> ans(n, 0);
    int r = 0, l = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            r++;
        }else{
            l++;
        }
        if(s[i] == 'L' && (s[i + 1] == 'R' || i == n - 1)){
            ans[i - l + 1] = l - (l / 2) + (r / 2);
            ans[i - l] = r - (r / 2) + (l / 2);
            r = l = 0;
        }
    }

    for(int i = 0; i < n; i++){
        if(i != n - 1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
}
