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

int main()
{
    ll n,i,j,k,l=1ll,m,cnt,ans=0;

    cin >> n;

   for(i=2;i*i<=n;i++)
   {
       cnt = 0;

       while(n>1 && n%i == 0)
       {
           n = n/i;

           cnt++;
       }
       if(cnt){
       // cout << i << " " << cnt << endl;
       m = (ll)sqrt(1+(8*cnt)) - 1;
       m /= 2;
       ans += m;
       }

   }
   if(n>2)ans++;

   cout << ans << endl;

}

