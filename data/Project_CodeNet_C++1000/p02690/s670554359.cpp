#include<bits/stdc++.h>
using namespace std;

#define IOS             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define watch(x);       cout << "\n" <<  #x << " is: " << x << "\n";
#define ll              long long int
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define pb              push_back
#define nl              cout<<"\n"
#define gcd(a,b)        __gcd(a,b)
#define sq(a)           (a)*(a)
#define loop(i,a,b)     for (ll i = a; i <= b; i++)
#define rloop(i,a,b)    for (int i = a; i >= b; i--)
#define sz(a)           a.size()
#define mod             1000000007
#define PI              2*acos(0.0)

ll Pow(ll base,ll power) {
   if (power == 0)
   return 1;
   else
   return (base * Pow(base, power-1));
}
int main()
{
    IOS
    int T=1;
    //cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        loop(i,-200,200)
        {
            loop(j,-200,200)
            {
                if(Pow(i,5)-Pow(j,5)==n)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }

    }
    return 0;
}
