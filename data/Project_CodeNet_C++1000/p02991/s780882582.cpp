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
 
int main(){
    ll n,m ;
    cin >> n >> m;
    vector<ll> g[n];
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
    }
    ll d[n][3];
    ll visit[n][3];
    rep(i,n) rep(j,3) {
        d[i][j]=inf;
        visit[i][j]=false;
    }
    
    queue<Pair> que;//頂点とどの段階か
    ll s,t;
    cin >> s >> t;
    s--;t--;
    que.push(make(s,0));
    d[s][0]=0;
    
    while(!que.empty()){
        Pair ima=que.front();
        que.pop();
        if(visit[ima.first][ima.second]) continue;
        visit[ima.first][ima.second]=true;
        for(ll b : g[ima.first]){
            ll modit=(ima.second+1)%3;
            if(visit[b][modit]) continue;
            else{
                d[b][modit]=d[ima.first][ima.second]+1;
                que.push(make(b,modit));
            }
        }
    }
    if(d[t][0]==inf) {kaku(-1);}
    else{kaku(d[t][0]/3);}
}

