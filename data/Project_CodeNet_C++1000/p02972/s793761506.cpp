#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;
const int N = 2e5 + 5;
ll n, arr[N];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> arr[i];
    vector<ll>ans;
    for(int i = n;i >= 0;--i)
    {
        arr[i] %= 2;
        if(arr[i])
        {
            ans.push_back(i);
            for(ll j = 1;j * j <= i;++j)
            {
                if(i % j == 0)
                {
                    arr[j]++;
                    if(j != i / j)
                        arr[i / j]++;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto &it : ans)
        cout << it << ' ';
    return 0;
}
