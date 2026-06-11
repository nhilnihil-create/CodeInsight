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
#include <deque>
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl
#define isort(a) sort(a.begin(),a.end())
#define ll long long

using namespace std;


#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

const ll inf =1000000007;
typedef pair<ll,ll> Pair;


typedef vector<ll> vl;

ll n,m,q;
ll a[55],b[55],c[55],d[55];
ll ans;

void keisan(vl vec){
    ll res=0;
    rep(i,q){
        if(vec[b[i]]-vec[a[i]]==c[i]) res+=d[i];
    }
    ans=max(ans,res);
}

void dfs(vl vec){
    if(vec.size()==n){
        keisan(vec);
    }
    else{
        ll last;
        if(vec.size()==0){
            last=1;
        }
        else{
            last=vec.back();
        }
        for(ll i=last;i<=m;i++){
            vec.pb(i);
            dfs(vec);
            vec.pop_back();
        }
    }
}


void solve(){
    cin >> n >> m >>q;
    ans=0;
    rep(i,q){
        cin >>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;b[i]--;
    }
    vl vec={};
    dfs(vec);
    kaku(ans);
}

int main(){
    solve();
}