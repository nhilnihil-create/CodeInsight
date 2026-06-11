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
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    for(int i = 60; i >= 0; i--){
        int cnt = 0;
        rep(j,n){
            if(a[j]>>i&1) cnt++;
        }
        if(cnt&1){
            rep(j,n){
                a[j] &= ~(1ll<<i);
            }
            ans += 1ll<<i;
        }
    }
    

    int rank = 0;
    for(int i = 60; i >= 0; i--){
        int j = rank;
        for(; j < n; j++){
            if(a[j]>>i&1){
                swap(a[rank],a[j]);
                break;
            }
        }
        if(j == n) continue;
        rep(k,n){
            if(k == rank) continue;
            if(a[k]>>i&1){
                a[k] ^= a[rank];
            }
        }
        rank++;
    }
    ll ans2 = 0;
    rep(i,rank) ans2 ^= a[i];
    ans2 *= 2;
    cout << ans+ans2 << endl;
}

