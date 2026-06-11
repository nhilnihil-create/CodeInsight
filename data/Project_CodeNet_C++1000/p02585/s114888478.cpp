#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#include <queue>
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    rep(i,n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i,n) cin >> c[i];
    ll ans=-10e10;
    rep(i,n) {
        int v=i;
        ll cycle_sum=0;
        int cycle_cnt=0;
        while(true) {
            cycle_cnt++;
            cycle_sum+=c[v];
            v=p[v];
            if(v==i) break;
        }
        ll path=0;
        int cnt=0;
        while(true) {
            cnt++;
            path+=c[v];
            if(cnt>k) break;
            int num=(k-cnt)/cycle_cnt;
            ll score=path+max(0ll,cycle_sum)*num;
            if(ans<score) ans=score;
            v=p[v];
            if(i==v) break;
        } 
    }
    cout << ans << endl;
}
