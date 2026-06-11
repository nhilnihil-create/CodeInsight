#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#define inf 1e9+7
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl;
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

typedef pair<ll,ll> Pair;
typedef set<ll> Set;
const ll MOD=inf;

const ll max_N=100005;
ll n,k;
vector<ll> g[max_N];
ll ans=1;

bool visit[max_N];

void dfs(ll a){//頂点持って遷移
    visit[a]=1;
    ll conti=1;
    if(a!=0) conti++;
    for(auto b: g[a]){
        if(visit[b]) continue;
        else{
            ans*=k-conti;
            ans%=MOD;
            dfs(b);
            conti++;
        }
    }
}


int main(){
    cin >> n >> k;
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    rep(i,n) {
        visit[i]=0;
    }
    ans*=k;
    dfs(0);
    kaku(ans);
}


