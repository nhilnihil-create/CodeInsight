#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, k, score = 0;
    string s;
    cin >> n >> k >> s;
    rep(i, n - 1)
    {
        if (s[i] == s[i + 1])
            score++;
    }
    int ans = min(score + 2 * k, n - 1);
    // cout << ans << endl;
    // char c = s[0];
    // rep(i, n)
    // {
    //     if (s[i] != c && k > 0){
    //         while(){
    //             s[]
    //         }
    //     }
    // }
    // rep(i, n)
    // {
    //     if (i == 0 && s[i] == 'L')
    //         continue;
    //     if (i == n - 1 && s[i] == 'R')
    //         continue;
    //     if (s[i] == 'R' && s[i + 1] == 'R')
    //         ans++;
    //     if (s[i] == 'L' && s[i - 1] == 'L')
    //         ans++;
    // }
    cout << ans << endl;
    return 0;
}