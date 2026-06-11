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
        ll N, D;
        cin >> N >> D;
        int res = 0;
        for (int i = 0; i < N; i++)
        {
            ll a, b;
            cin >> a >> b;
            if (a * a + b * b <= D * D)
                res++;
        }
        cout << res << "\n";
    }
    return 0;
}