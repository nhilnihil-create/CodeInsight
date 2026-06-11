#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    ll ans=0;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans = i;
        }
    }
    cout << (ans-1)+(n/ans-1);
    return 0;
}