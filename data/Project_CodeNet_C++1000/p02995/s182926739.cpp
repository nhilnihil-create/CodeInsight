//FIRST THINK THEN CODE.

#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
#define MOD 998244353
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  a%=m;
  ll ans=1LL;
  while(b)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
 
return ans;
}
 
ll poww(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }
 
return ans;
}

const ll N=5e5+5;

ll sp[N];

void sieve(){
  for(int i=2;i<N;i++)sp[i]=i;

    for(int i=2;i*i<N;i++){
      if(sp[i]==i){
      for(int j=i*i;j<N;j+=i){
        sp[j]=i;
      }
    }
}

}

ll fac[N],inv[N];

ll p=1e9+7;

void fill(){
  fac[0]=inv[0]=1;

  for(int i=1;i<N;i++){
    fac[i]=fac[i-1]*i%p;
    inv[i]=powM(fac[i],p-2,p);
  }
}

ll c(ll a,ll b,ll p){
if(a<b)return 0;

  return (fac[a]*inv[a-b]%p)*(inv[b])%p;
}


ll lcm(ll a,ll b)
{
  return (a*b)/(__gcd(a,b));
}

int main()
{ 

  IOS;


ll a,b,c,d;

cin>>a>>b>>c>>d;

ll l1=a%c?c+a-a%c:a,r1=b-b%c;

ll l2=a%d?d+a-a%d:a,r2=b-b%d;

ll e=lcm(c,d);

ll l3=a%e?e+a-a%e:a,r3=b-b%e;

ll cnt=0;

if(l1<=r1){
cnt+=1+(r1-l1)/c;
}



if(l2<=r2){
cnt+=1+(r2-l2)/d;
}

if(l3<=r3){
cnt+=-1-(r3-l3)/e;
}

cnt=(b-a+1)-(cnt);

cout<<cnt<<endl;

return 0;
 
}

