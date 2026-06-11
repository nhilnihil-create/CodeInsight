#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d) for ( auto blockTime = make_pair(chrono::high_resolution_clock::now(), true);blockTime.second;\
debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)
#define li long long int
#define ld long double
#define eb push_back
#define pb pop_back
#define INF 1e18+10
#define MINF -1e18-10
#define rep(i,a,b) for(li i=a;i<b;i++)
#define size(a) a.size()
#define rev(a) reverse(a.begin(),a.end())
#define len(a) a.length()
#define f first
#define s second
#define sort(a) sort(a.begin(),a.end())
#define vli vector<li>
#define vvli vector<vli >
#define pli pair<li,li>
#define vpli vector<pli>
#define inp(t) li t;cin>>t; while(t--)
using namespace std;
const li mod = 1e9+7;
#define MAXN 1000005 

li power(li a, li b) { a%=mod; li ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=mod) ret%=mod;if(a>=mod) a%=mod;b>>=1;}return ret;}
li add(li a,li b) { return (((a%mod)+(b%mod))%mod);}
li sub(li a,li b) { return (((a%mod)-(b%mod))%mod);}
li mul(li a,li b) { return (((a%mod)*(b%mod))%mod);}

bool isprime(li n)
{
  if (n == 1)
    return false;
  int i = 2;
  while (i*i <= n){
      if (n % i == 0)return false;
      i += 1;
  }
  return true;
}

li lcm(li a,li b)
{
    return ((a*b)/__gcd(a,b));
}

void solve()
{
  li n;
  string s;

  cin>>n;
  cin>>s;

  li b=0,r=0,g=0;

  for(li i=0;i<n;i++)
  {
    if(s[i]=='B')
      b++;
    else if(s[i]=='R')
      r++;
    else if(s[i]=='G')
      g++;
  }

  li total = b*g*r;
  for(li i=0;i<n;i++)
  {
    for(li j=i;j<n;j++)
    {
      li k = 2*j-i;

      if( k<n && s[i]!=s[j] && s[i]!=s[k] && s[j]!=s[k])
        total--;
    }
  }

  cout<<total<<endl;
}
int main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
    
    return 0;
}