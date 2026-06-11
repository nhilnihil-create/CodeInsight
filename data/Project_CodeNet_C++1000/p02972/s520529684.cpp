#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep(i, n) cin >> a[i + 1];
    vector<int> H(n + 1);
    for (int i = n; i >= 1; i--)
    {
        int sum = 0;
        int j = i;
        while (j <= n)
        {
            sum += H[j];
            j += i;
        }
        if (sum % 2 == a[i])
            H[i] = 0;
        else
            H[i] = 1;
    }

    //指定の形に変換
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (H[i] == 1)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
}