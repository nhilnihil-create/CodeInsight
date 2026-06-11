#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;

#define pf(n) cout << n << endl
#define ps() cout <<" ";
#define sf(n) cin >> n
#define in(i,n) for (int i = 0; i < n; i++) 2
#define mn -
#define pls +
#define mod %
#define E =
#define EE ==
#define le <=
#define ge >=

inline void SUM(ll &x,ll y)
{
    x=x+y;
}
inline void DIFF(ll &x,ll y)
{
    x=x-y;
}
ll c E 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll sum E 0;
    int I E 1;
    std::vector<ll> v;
    while(sum<n)
    {
        ll test E 1;
        for (int i = 0; i <I ; ++i)
        {
            test E test * 26;
        }
        SUM(sum,test);
        v.push_back(test);
        I E I pls 1;    
    }
    
    for (int i = 0; i < v.size(); ++i)
    {
        //cout<<n;ps();pf(v[i]);
        if(v[i] ge n)break;
        DIFF(n,v[i]);
    }
    
    double X E n;
    std::vector<int> vt;
    for (int i = 0; i < v.size(); ++i)
    {
        n E ceil(X);
       
        int d E (n mod 26);
        X E(X/26);
        if(!d)d E 26;
        vt.push_back(d pls 96);
        
    }
    
    reverse(vt.begin(),vt.end());
    for (auto x:vt)
    {
        char c E x;
        cout<<c;
    }
    return 0;
}
