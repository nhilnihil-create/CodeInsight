#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

int main()
{
    int M,D;
    cin >> M >> D;
    ll ans = 0;
    for (int i = 1; i <= M;i++)
    {
        for (int j = 1; j <= D;j++)
        {
            if(j > 9){
                int pre2 = j / 10;
                int pre1 = j - pre2 * 10;
                if (pre2 > 1 && pre1 > 1)
                {
                    if(i == pre2*pre1){
                        ans++;

                    }
                }
                else{

                }
            }
        }
    }
    cout << ans << endl;
}