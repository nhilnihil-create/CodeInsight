#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
#define txti freopen("input.txt", "r", stdin);
#define txto freopen("output.txt", "w", stdout);
//#define mod 100000007

#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 

bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.second > b.second )
        return true;
    if( a.second==b.second && a.first > b.second )
       return true;
 
    return false;
 }
//me
ll const mod = 1e9+7;//998244353;
ll const inf = 3e5+1;
ll row[inf], col[inf];
void solve()
{

    ll h,w; cin >> h >> w;
    ll m; cin >> m;
    set<pair<ll,ll>> s;
    while(m--){
        ll x,y; cin >> x >> y;
        row[x]++;
        col[y]++;
        s.insert({x,y});
    }
    ll maxX=0, maxY=0;
    for(ll i=1; i<=h; i++)
        maxX = max(maxX, row[i]);
    for(ll i=1; i<=w; i++)
        maxY = max(maxY, col[i]);
    ll ans = maxX + maxY -1;

    vector<ll> allmaxX, allmaxY;
    for(ll i=1; i<=h; i++)
        if(row[i]==maxX) allmaxX.pb(i);
    for(ll i=1; i<=w; i++)
        if(col[i]==maxY) allmaxY.pb(i);
    
    for(auto A : allmaxX){
        for(auto B : allmaxY)
            if(!s.count({A,B}))
            {
                ans++; goto printing;
            }
    }
    printing:
    cout << ans << endl;
}

int main() {
Knucklehead 
/*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
        
        ll t;
        /**/t=1;
        /*/cin>>t;/**/
        f(testcases,0,t){
            solve();
        }
 
 
    return 0;
}
