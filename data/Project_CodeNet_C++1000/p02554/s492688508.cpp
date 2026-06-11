#include <iostream>
using namespace std;
using ll = long long int;
const ll MOD = 1000000007;

//aのn乗をMODで割った余りを求める関数
ll mypow(ll a, ll n){
    ll ans = 1;
    for(ll i = 0; i < n; i++){
        ans *= a;
        ans %= MOD;
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    ll ans = mypow(10, n) - mypow(9, n) - mypow(9, n) + mypow(8, n);
    //ansが負の数になっている可能性を考慮し　正の数になるよう適当な数を足す
    ans += MOD*2;
    //改めてMODで割った余りを求める
    ans %= MOD;
    cout << ans << endl;
}