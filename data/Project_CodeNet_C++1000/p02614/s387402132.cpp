#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <queue>
#include <queue>
#include <stack> 
#include <sstream>
#include <set>

typedef  long long ll;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = { 0, 1, 0,-1};
const int INF = 1e9;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
#define REVERSE(a) reverse(a.begin(),a.end())
int guki (int a){
    if(a%2==0) return 0;
    else return 1;
}
int gcd(int a, int b){
    if(a%b==0){
        return b;
    }else{
        return (gcd(b,a%b));
    }
}
int lcm(int a, int b){
    int x = gcd(a,b);
    return (a*b/x);
}

using namespace std;
// now

struct UnionFind {
    vector<int> d;
    UnionFind(int n=0) : d(n,-1){}
    int Find (int x){//根の番号を探す
        if(d[x] < 0) return x;
        return d[x] = Find(d[x]);
    }
    bool unite (int x, int y){
        x = Find(x); y = Find(y);
        if(x == y ) return false;
        if(d[x] < d[y]){
            swap(x,y);
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    } 

    bool same(int x, int y){
        return Find(x) == Find(y);
    }
    int size(int x) {
        return (-d[Find(x)]);
    }
};


ll nCr (ll n, ll r){
    ll ans = 1;
    for(ll i = n ; i > n-r ; i --){
        ans *= i;
    }
    for(ll i = 1 ; i<= r; i ++){
        ans /= i;
    }
    return ans ;
}

int nPr (int n,int r){
    int ans = 1;
    for(int i = n ; i > n-r ; i --){
        ans *= i;
    }
    return ans ;
}
 ll modd = 1e9+ 7;
ll wa (ll n,ll mi, ll ma){
    ll ans  = n * (mi+ma) /2;
    return ans;
}
ll kw(ll k,ll n){
    
    ll ans  =0;
    ll mi,ma;
    mi= wa(k,0,k-1);
    
    ma = wa(k,n-k+1,n);
    
    return (ma-mi +1)%modd;
}
char grid[7][7];
int h,w,k;

int main(){

    cin >> h >> w >> k;

    

    REP(i,h){
        REP(j,w){
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    REP(i,1<<h){
        REP(j,1<<w){
            int cnt = 0;
            REP(i1,h){
                REP(j1,w){
                    if(i>>i1 &1)continue;
                    if(j >> j1&1)continue;
                    if(grid[i1][j1] == '#')cnt++;
                }
            }
            if(cnt == k) ans ++;
        }

    }

    cout << ans <<endl;


}



