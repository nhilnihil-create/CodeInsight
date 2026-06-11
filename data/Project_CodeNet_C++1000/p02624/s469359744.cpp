#include<bits/stdc++.h>
using namespace std;
const int MAX = 2e5+9 ;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " = " << x << endl;
typedef long long ll;
int numdiv (int n)
{
    if (n==1)
        return 1;
    int ret=2;
    for (int i=2; i*i<=n; ++i)
    {
        if (n%i==0)
        {
            ++ret;
            if (n%(n/i)==0 && n/i!=i)
                ++ret;
        }
    }
    return ret;
}
ll pr[10000009];
int main()
{
    fastIO

    for (int i=1; i<=10000009; ++i)
    {
        for (int j=i; j<=10000009; j+=i)
        {
            ++pr[j];
        }
    }

    int n;
    cin>>n;

    ll ans=0;

    for (ll i=1; i<=n; ++i)
    {
        ans+=pr[i]*i;
    }
    cout<<ans;








}
