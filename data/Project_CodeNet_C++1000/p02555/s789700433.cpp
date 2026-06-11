#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define maxn 5000
#define mod 1000000007
ll ans[maxn],n;
void task()
{
    for(int i = 0; i <= 2; i++)
    {
        ans[i] = 0;
    }
    ans[3] = 1;
    for(int i = 4; i <= 2005; i++)
    {
        ans[i] = (ans[i-1] + ans[i-3]) % mod;
    }
}
int main()
{
    cin >> n;
    task();
    cout << ans[n];
    return 0;
}
