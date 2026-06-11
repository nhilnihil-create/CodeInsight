#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n = str.size() + 1;
    vector<int> cnt(n); // a[i] について、cnt[i] = max(左に連続する < の個数, 右に連続する > の個数)

    // 左から < をカウントする
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == '<')
        {
            cnt[i + 1] = (std::max)(cnt[i + 1], cnt[i] + 1);
        }
    }

    // 右から > をカウントする
    for (int i = n - 2 ; i >= 0; --i)
    {
        if (str[i] == '>')
        {
            cnt[i] = (std::max)(cnt[i], cnt[i+1] + 1);
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += cnt[i];
    }
    cout << ans << endl;
    return 0;
}
