#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int mod = 1000000007;

int main()
{
    IOS
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        ll res = (1ll)*a[n-1];
        int cnt = n - 2, i = n - 2;
        while (cnt >= 2)
        {
            res += 2*(1ll)* a[i];
            cnt -= 2;
            i--;
        }
        if (cnt == 1)
            res += a[i];
        cout << res;
    }
    return 0;
}