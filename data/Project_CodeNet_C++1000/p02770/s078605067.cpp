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
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int k,q; cin >> k >> q;
    vector<int> d(k);
    rep(i,k) cin >> d[i];
    rep(i,q){
        int n,x,m; cin >> n >> x >> m;
        vector<int> d2 = d;
        x %= m;
        int ans1 = 0;
        int ans2 = 0;
        ll sum = 0;
        rep(j,k){
            d2[j] %= m;
            if(d2[j] == 0) ans2++;
            sum += d2[j];
        }
        int s = (n-1)/k,r = (n-1)%k;
        ll sum2 = 0;
        ans2 *= s;
        rep(j,r){
            sum2 += d2[j];
            if(d2[j] == 0) ans2++;
        }
        ll last = x+sum*s+sum2;
        ans1 = last/m;
        int ans = n-1-ans1-ans2;
        cout << ans << endl;


    }
}
