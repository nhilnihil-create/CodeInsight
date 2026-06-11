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
#define loop(i,a,b)     for (int i = a; i <= b; i++)
#define rloop(i,a,b)    for (int i = a; i >= b; i--)
#define sz(a)           a.size()
#define mod             1000000007
#define PI              2*acos(0.0)

vector<ll> factorize(ll x) {
    vector<ll> res;
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i!=0) continue;
        int num=0;
        while(x%i==0)
        {
            num++;
            x/=i;
        }
        res.pb(num);
    }
    if(x!=1) res.pb(1);
    return res;
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
        if(n==1)
        {
            cout<<0;
            nl;
            continue;
        }
        vector<ll>v=factorize(n);
        ll cnt=0;
        for(auto a:v)
        {
            ll temp=a;
            ll i=1;
            while(i<=temp)
            {
                temp-=i;
                i++;
                cnt++;
            }
        }
        cout<<cnt;
        nl;

    }
    return 0;
}
