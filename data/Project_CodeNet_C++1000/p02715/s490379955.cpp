#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLMAX (1ll << 60) - 1
#define INTMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1

#define numberOfSetBits(S) __builtin_popcount(S) // __builtin_popcountl(S) __builtin_popcountll(S)
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<endl;
#define printii(x)  for(auto it=x.begin();it!=x.end();it++) cout<<*it.F<<' '<<*it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)
vi ans;

ll power(ll x, unsigned ll y, unsigned ll m=MOD) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,k;
    cin>>n>>k;
    ans.resize(k+1);
    for(ll i=k;i>=1;i--){
    	ans[i] = power(k/i, n);
        for(int j=2*i;j<=k;j+=i){
            ans[i]-=ans[j];
            ans[i]%=MOD;
        }
    }
    ll s = 0;
    for(ll i=1;i<=k;i++){
        s+=(ans[i]*i)%MOD;
        s%=MOD;
    }
    if(s<0){
    	s+=MOD;
    }
    cout<<s;
    
    

    return 0;
}





