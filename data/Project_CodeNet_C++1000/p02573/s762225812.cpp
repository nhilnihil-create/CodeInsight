
#include<bits/stdc++.h>


using namespace std;

using ll   = long long;
using ii   = pair   < int , int >;
using i3   = pair   < int , ii  >;
using li   = pair   < ll  , int >;
using lii  = pair   < ll  , ii  >;
using pll  = pair   < ll  , ll  >;
using vi   = vector < int       >;
using vl   = vector < ll        >;
using vii  = vector < ii        >;
using vli  = vector < li        >;
using vpll = vector < pll       >;
using vi3  = vector < i3        >;
using vlii = vector < lii       >;


const int N = 2e5 + 5;
const ll INF = 1e17 + 7;
const double eps = 1e-9 , PI = acos(-1);



int n , m;

int sz[N];
int p[N];

int get(int x) { return x == p[x] ? x : p[x] = get(p[x]); }

void join(int x , int y) {
    x = get(x);
    y = get(y);

    if(x == y) return;

    if(rand() & 1) swap(x , y);

    p[x] = y;
    sz[y] += sz[x];
}


void solve(int testCase){

    scanf("%d %d" , &n , &m);

    for(int i = 1 ; i <= n ; i ++) {
            p [i] = i;
            sz[i] = 1;
    }

    for(int i = 0 ; i < m ; i ++) {
            int u , v;
            scanf("%d %d" , &u , &v);
            join(u , v);
    }

    int ans = 0;
    for(int i = 1 ; i <= n ; i ++) {
            ans = max(ans , sz[get(i)]);
    }

    printf("%d\n" , ans);

}

main(){

    int t = 1;
    // scanf("%d" , &t);

    for(int testCase = 1 ; testCase <= t ; testCase ++){
            solve(testCase);
    }

    return 0;
}
