#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i=n; i<(int)m; i++)
#define ROF(i,n,m) for(int i=n; i>(int)m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ri(a) scanf("%d",&a)
#define rii(a,b) ri(a),ri(b)
#define riii(a,b,c) rii(a,b),ri(c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) lri(a),lri(b)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define all(x) x.begin(),x.end()
#define debug true
#define dprintf debug && printf

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e6+5;

int fact2(int n){
    int ret = 0;
    for(int i = 1; (1<<i) <= n; i++)
        ret += (n>>i);
    return ret;
}

int comb2(int n, int k){
    int cnt = fact2(n) - fact2(n-k) - fact2(k);
    return cnt == 0;
}

char s[MAXN];
int a[MAXN];
int n;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ri(n);
    scanf("%s", s);
    FOR(i,0,n) a[i] = s[i] - '1';

    int par = 0;
    FOR(i,0,n) par ^= ((a[i]&1) & (comb2(n-1, i)));
    if(par){
        printf("1\n");
    }
    else{
        FOR(i,0,n) {
            if(a[i] == 1) {printf("0\n"); return 0;}
            a[i] >>= 1;
        }
        par = 0;
        FOR(i,0,n) par ^= ((a[i]&1) & (comb2(n-1,i)));
        printf(par ? "2\n" : "0\n");
    }

    return 0;
}
