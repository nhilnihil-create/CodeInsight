#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    ll n,k;
    cin >> n  >> k;
    vl vec(n);
    rep(i,n) cin >> vec[i];
    ll cnt = 0;

    rep(i,n){
        reps(j,i+1,n){
            if(i == j) continue;
            if(vec[i] > vec[j]) cnt++;
        }
    }
    //cout << cnt << endl;
    ll mod = 1e9+7;
    ll sum1 = (cnt * k) % mod;
    
    ll cnt2 = 0;
    rep(i,n){
        rep(j,n){
            if(i == j)continue;
            if(vec[i] > vec[j]) cnt2++;
        }
    }

    ll sum2 = 0;
    if(k % 2 == 0){
        sum2 = k/2;
        sum2 = (sum2*(k-1)) % mod;
    }else{
        sum2 = (k-1)/2;
        sum2 = (sum2*k) % mod;
    }
    
    sum2 = (sum2*cnt2) % mod;
    ll ans = (sum1 + sum2) % mod;

    cout << ans << endl;
    return 0;
}
