#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 2e5+5, M = 1e6+6, OO = 0x3f3f3f3f, MOD  = 998244353;

long long power(ll a, ll b, ll m){  // Fast power with mod;
    if(!b)  return 1;
    ll t = power(a, b>>1, m)%m;
    return ((t*t)%m * (b&1 ? a : 1)%m)%m;
}

unsigned long long modInverse(ll n, ll p) 
{ 
    return power(n, p-2, p); 
} 

// int tc;
// int n, s;
// vector<int> vec;
// ll ans = 0;
// void solve(int idx = 0, int target = s)
// {
//     if(target == 0)
//     {
//         ans = (ans%MOD + power(2, (ll) n - (ll) vec.size(),MOD))%MOD;
//         cout<<vec.size()<<endl;
//             for(auto x : vec)
//                 cout<<x<<" ";
//             cout<<endl;
//             return;
//     }
//     if(idx == n)
//     {
//         return ;
//     }
//     if(arr[idx] <= target)
//     {
//         vec.push_back(arr[idx]);
//         solve(idx+1, target - arr[idx]);
//         vec.pop_back();
//         solve(idx+1, target);
//     }
//     else
//         solve(idx+1, target);
// }


ll mem[3005][3005];
ll arr[3005];


int main()
{
    FIO
    ll n, s;
    cin>>n>>s;
    for(int i = 0 ; i<n ; i++)
        cin>>arr[i];
    sort(arr, arr+n);
    if(arr[0] > s)
        return cout<<0, 0;
    for(int i = 0; i <= n ; i++)
        for(int j = 0; j <= s; j++)
            mem[i][j] = 0;

    ll tmp = modInverse(2, MOD);
    mem[0][0] = power(2, n, MOD);
    for(ll i = 0 ; i <= n ; i++)
    {
        for(ll j = 0 ; j <= s; j++)
        {
            mem[i+1][j] += mem[i][j];
            mem[i+1][j] %= MOD;
            if(j + arr[i] <= s)
            {
                mem[i+1][j + arr[i]] += (mem[i][j] * tmp);
                mem[i+1][j+arr[i]] %= MOD;
            }
        }
    }
    cout<<mem[n][s]<<endl;
    return 0;
}