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
#define endl '\n'
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define print(x)    for(auto it:x) cout<<it<<' '; cout<<endl;
#define printii(x)  for(auto it:x) cout<<it.F<<' '<<it.S<<'\t';  cout<<endl;
#define in(x,n)   for(int e=0;e<n;e++){ll y;cin>>y;x.pb(y);}

#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define vvii vector<vii>
#define viii vector<pair<ii,ll>>
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mc(a,b,c) mp(mp(a,b),c)
vi fact;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,t,m,y,z;
    cin>>n;
    x = n-1;
    fact.pb(x);
    if(n==2){
        cout<<1;
        return 0;
    }
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            fact.pb(i);
            if(i!=(x/i))
                fact.pb(x/i);
        }
    }
    ll ans = 0;
    ans+=fact.size();
    fact.clear();
    fact.pb(n);
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            fact.pb(i);
            if(i!=(n/i))
                fact.pb(n/i);
        }
    }
    for(int i=0;i<fact.size();i++){
        y = n;
        while(y%fact[i]==0){
            y/=fact[i];
        }
        if(y%fact[i]==1){
            ans++;
        }
    }
    cout<<ans;
    
    


    return 0;
}               