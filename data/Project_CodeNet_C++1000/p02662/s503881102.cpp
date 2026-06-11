#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
using less_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using great_set = tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
const int N = 2e3+69;
#define ALL(x) begin(x),end(x)
#define sz(x) (ll)x.size()
const int OO = 0x3f3f3f3f;
const int mod = 998244353;


ll n, s;
ll arr[3069];

ll mem[3069][3069];
ll solve(int idx, int sum)
{
    ll op1, op2;
    if(idx == n)
    {
        if(sum == s)
            return 1;
        else
            return 0;
    }
    if(mem[idx][sum] != -1)
        return mem[idx][sum];
    op1 = op2 = 0;
    if(sum + arr[idx] <= s)
        op1 = solve(idx+1, sum+arr[idx])%mod;
    op2 = (2*solve(idx+1, sum))%mod;

    return mem[idx][sum] = (op1 + op2)%mod;
}


int main()
{
    FIO
    memset(mem, -1, sizeof mem);
    cin >> n >> s;
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    cout << solve(0, 0)%mod << "\n";
    return 0;
}
