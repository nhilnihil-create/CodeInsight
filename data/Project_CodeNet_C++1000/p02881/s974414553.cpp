#include <bits/stdc++.h>
#define ll long long
#define mx 1000025
using namespace std;
//bool a[mx];
//ll prime[mx], j;
//void seive()
//{
//    ll i;
//    for(i = 2; i * i <= mx; i++)
//    {
//        if(!a[i])
//        {
//            for(ll j = i * i; j <= mx; j+=i)
//            {
//                a[j] = 1;
//            }
//        }
//    }
//    for(i = 2; i <= mx; i++)
//    {
//        if(!a[i])prime[j++] = i;
//    }
//}
bool is_prime(ll n)
{
    for(ll i = 2; i * i <= n; i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
ll inf = 1e18;
int main()
{
    ll n, res = inf;
    cin>>n;
    if(is_prime(n)){cout<<n-1<<endl;return 0;}
    for(ll i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ll d = n/i;
            res = min(res, ((d-1)+(i-1)));
        }
    }
    cout<<res<<endl;
}
