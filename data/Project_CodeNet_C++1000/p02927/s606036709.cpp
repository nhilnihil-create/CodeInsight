#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int m, d;
    cin >> m >> d;
    int ans = 0;
    
    reps(i, 1, m + 1) {
        reps(ii, 1, d + 1) {
            int one = ii % 10;
            int ten = ii / 10;
            
            if ((one >= 2) && (ten >= 2) && ((one * ten) == i)) {
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
