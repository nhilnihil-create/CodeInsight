#include <bits/stdc++.h>
#define INF 1e7
#define dsec 86400

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;
typedef tuple<double,double,double> tdd;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}


ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}


int main()
{
    ll N,M; cin >> N >> M;
    vector<ll>a(N);
    for(ll i = 0; i < N; i++) cin >> a[i];
    ll t = 0;
    for(ll i = 0; i < N; i++)
    {
        if(i == 0)
        {
            while(a[i]%2 == 0)
            {
                t++;
                a[i] /= 2;
            }
        }
        else
        {
            ll tmp = 0;
            while(a[i]%2 == 0)
            {
                tmp++;
                a[i] /= 2;
            }
            if(t != tmp)
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    ll l = 1;
    for(ll i = 0; i < N; i++)
    {
        l = lcm(l,a[i]);
        if(l > M)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    M >>= (t-1);
    M /= l;
    ll ans = (M+1)/2;
    cout << ans << endl;
}