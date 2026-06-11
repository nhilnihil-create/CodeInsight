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
set<ll> cnt[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,m,y,z;
    string s,t;
    cin>>s>>t;
    n = s.size();
    for(int i=0;i<n;i++){
        cnt[s[i]-'a'].insert(i+1);
    }
    n = t.size();
    for(int j=0;j<n;j++){
        if(!cnt[t[j]-'a'].size()){
            cout<<-1;
            return 0;
        }
    }
    ll curr = 0,foo=0;
    for(int i=0;i<n;i++){
        auto it = cnt[t[i]-'a'].upper_bound(curr);
        if(it==cnt[t[i]-'a'].end()){
            foo++;
            curr = *cnt[t[i]-'a'].begin();
        }
        else{
            curr = *it;
        }
    }
    n = s.size();
    cout<<foo*n+curr;
    

    


    return 0;
}