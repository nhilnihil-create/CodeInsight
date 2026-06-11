#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<numeric>
#include<atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int n,q; cin >> n >> q;
    fenwick_tree<ll> fw(n);
    rep(i,n){
        int a; cin >> a;
        fw.add(i,a);
    }
    rep(i,q){
        int t; cin >> t;
        if(t == 0){
            int p,x; cin >> p >> x;
            fw.add(p,x);
        }
        else{
            int l,r; cin >> l >> r;
            cout << fw.sum(l,r) << "\n";
        }
    }
}

