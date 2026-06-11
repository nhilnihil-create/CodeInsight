#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const int MAX = 2e+5;
ll cnt[10][10];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        cnt[s[0] - '0'][s[s.size() - 1] - '0']++;
    }
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
    return 0;
}