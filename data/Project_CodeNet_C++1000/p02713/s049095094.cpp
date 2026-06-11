#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
ll gcd(ll a, ll b, ll c)
{
    ll ans1;
    ans1 = __gcd(a, b);
    ans1 = __gcd(ans1, c);

    return ans1;

}
int main()
{
    ll ans = 0, i, j, k, n;
    cin>>n;
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j<=n; j++)
        {
            for(k = 1; k<=n; k++)
            {
              ans+=gcd(i, j, k);
              //printf("%lld %lld %lld and gcd %lld", i, j, k, gcd(i, j, k));
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
