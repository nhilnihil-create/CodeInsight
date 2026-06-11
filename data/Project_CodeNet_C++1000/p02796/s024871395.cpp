#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll zero = 0;
const ll INF = 10000000000000000; //10^16
const ll MOD = 1000000007; //10^9+7

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> X(N+1);
    for(ll i = 1; i < N+1; i ++){
        cin >> X.at(i).first >> X.at(i).second;
    }
    sort(X.begin() + 1, X.end());
    
    
    vector<pair<ll,ll>> dp(N+1); //i個目まででの最大数と一番右にあるやつの右端
    dp.at(0) = make_pair(zero, zero);
    ll one = 1;
    dp.at(1) = make_pair(one, X.at(one).first + X.at(one).second );
    
    for(int i = 2; i < N+1; i++){
        if( X.at(i).first - X.at(i).second >= dp.at(i-1).second ){
            dp.at(i) = make_pair(dp.at(i-1).first + 1, X.at(i).first + X.at(i).second);
        }
        else{
            dp.at(i) = make_pair(dp.at(i-1).first, min(dp.at(i-1).second,  X.at(i).first + X.at(i).second));
        }
    }
    
    printf("%lld\n", dp.at(N).first);
    
    
}
