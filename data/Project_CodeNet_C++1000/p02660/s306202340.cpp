#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    ll n;
    cin >> n;

    map<ll, int> mp;
    for(ll i = 2; i*i <= n; i++)
    {
        while(n%i == 0)
        {
            n /= i;
            mp[i]++;
        }
    }
    if(n != 1) mp[n]++;

    int ans = 0;
    for(auto x : mp)
    {
        int t = x.second;
        for(int i = 1; i < 100; i++)
        {
            if(i > t) break;
            ans++;
            t -= i;
        }
    }
    cout << ans << endl;


    return 0;
}