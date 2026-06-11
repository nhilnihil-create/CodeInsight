#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mx 1000025
using namespace std;
bool a[mx];
ll prime[mx];
void seive()
{
    ll i, j;
    for(i = 2; i * i <= mx; i++)
    {
        if(!a[i])
        {
            for(ll j = i * i; j <= mx; j+=i)
            {
                a[j] = 1;
            }
        }
    }
    for(i = 2, j = 0; i <= mx; i++)
    {
        if(!a[i])prime[j++] = i;
    }
}
ll chck(ll x)
{
    for(int i = 1; i <= 64; i++)
    {
        if((i*(i+1))/2 > x)return i-1;
    }
}
int main()
{
    seive();
    vector <ll> res;
    ll n, j = 0, cnt, ans = 0;
    cin>>n;
    for(int i = 0; prime[i] * prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
        {
            cnt = 0;
            while(n%prime[i]== 0)
            {
                n /= prime[i];
                cnt++;
            }
            res.pb(cnt);
        }
    }
    if(n > 1)res.pb(1);
    for(int i = 0; i < res.size(); i++)
    {
        ans += chck(res[i]);
    }
    cout<<ans<<endl;
}
