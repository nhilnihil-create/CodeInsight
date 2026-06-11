#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<long long> a(n), cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    long long all = 0;
    for (int i = 0; i < n + 1; i++) all += cnt[i] * (cnt[i] - 1) / 2;
    long long ans;
    for (int i = 0; i < n; i++)
    {
        ans = all - (cnt[a[i]] - 1);
        cout << ans << endl;
    }
}