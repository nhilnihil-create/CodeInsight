#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vpi = vector<pii>;
using vl = vector<ll>;
using vll = vector<vl>;
using vpl = vector<pll>;
using vs = vector<string>;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main()
{
    int n;
    ll m;
    cin >> n >> m;
    vl as;
    as.resize(n);
    for(int i=0; i<n; i++) cin >> as.at(i);

    vl halfas(n);
    for(int i=0; i<n; i++)
    {
        if(as.at(i)%2 == 0)
        {
            halfas.at(i) = as.at(i) / 2;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }

    ll two = 1;
    ll cp0 = halfas.at(0);
    while(true)
    {
        if(cp0%2==0)
        {
            two *= 2;
            cp0 /= 2;
        }
        else break;
    }

    ll num = 1;
    for(int i=0; i<n; i++)
    {
        // cout << "---" << endl;
        // cout << halfas.at(0) % two << endl;
        // cout << (halfas.at(i)%two) % 2 << endl;
        if((halfas.at(0) % two != 0) || ((halfas.at(i)/two) % 2 == 0))
        {
            cout << 0 << endl;
            return 0;
        }
        num = lcm(num, halfas.at(i));
    }
    ll ans = m/num;
    if(ans%2) ans = (ans+1) / 2;
    else ans /= 2;
    cout << ans << endl;
    return 0;
}
