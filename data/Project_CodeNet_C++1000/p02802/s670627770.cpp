#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N, M;
int main()
{
    cin >> N >> M;
    vector<bool> p(M, false);
    vector<int> cnt(N, 0);
    int ans = 0, pena = 0;
    int prob;
    string s;
    rep(i, 0, M)
    {
        cin >> prob >> s;
        if (p[prob - 1] == false && s == "AC")
        {
            p[prob - 1] = true;
            ans++;
            pena += cnt[prob - 1];
            cnt[prob - 1] = 0;
        }
        else if (p[prob - 1] == false)
        {
            cnt[prob - 1]++;
        }
    }

    cout << ans << " " << pena << endl;
    return 0;
}
