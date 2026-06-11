#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define         pb         push_back
#define         sf(x)      scanf("%d",&x)
#define         sfl(x)     scanf("%lld",&x)
#define         pf(x)      printf("%d\n",x)
#define         pfl(x)     printf("%lld\n",x)
#define         endl       '\n'
#define         pii        pair<int,int>
#define         mapii      map<int,int>
#define         mapll      map<ll,ll>
#define         mapci      map<char,int>
#define         mapcl      map<char,ll>
#define         mapsi      map<string,int>
#define         mapsl      map<string,ll>
#define         pll        pair<ll,ll>
#define         vi         vector<int>
#define         vl         vector<ll>
#define         vd         vector<double,double>
#define         all(c)     c.begin(),c.end()
#define         F          first
#define         S          second
#define         mp         make_pair
#define        ftc(x)      cerr << #x << ": " << x << " " << endl;
#define         PI         acos(-1)
#define         lcm(a,b)   ((a*b)/__gcd(a,b))
#define        optimize    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define        sqr(a)       ((a)*(a))
#define         MOD     2019

ll binPow(ll a, ll q)
{
    a %= MOD;
    if (q == 0) return 1;
    return ((q % 2 == 1 ? a : 1) * binPow(a * a, q / 2)) % MOD;
}
mapll mpp;
int main()
{
    ll i,j,k,l,m,n;

    string s;

    cin >> s;

    n = s.size();

    ll rem[n+10],ans=0;
reverse(all(s));
    rem[0] = (binPow(10,0) * (s[0]-'0'))%MOD;
    mpp[rem[0]]++;
    for(i=1; i<n; i++)
    {
        rem[i] = (rem[i-1] + (binPow(10,i) * (s[i]-'0'))%MOD)%MOD;
        if(rem[i]==0)ans++;
        ans += mpp[rem[i]];
        mpp[rem[i]]++;

    }

    cout << ans << endl;


}
