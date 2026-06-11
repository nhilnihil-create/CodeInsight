#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

ll combination(int n, int r)
{
    if (r == 0 || r == n)
        return (1);
    else if (r == 1)
        return (n);
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

int main()
{
    int n;
    ll ans;

    cin >> n; 
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }

    sort(s.begin(), s.end());
    ans = 0;
    int cnt = 0;
    rep(i,n-1) {
        if (s[i] == s[i + 1])
            ++cnt;
        else {
            if (cnt>0)
                ans += combination(cnt+1, 2);
            cnt = 0;
        }
    }
    if (cnt > 0)
        ans += combination(cnt + 1, 2);

    cout << ans << endl;

    return 0;
}
