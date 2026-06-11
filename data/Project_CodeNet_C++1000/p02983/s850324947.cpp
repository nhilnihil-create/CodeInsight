#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    const int value = 2019;
    ll L, R;
    cin >> L >> R;
    ll num = R - L + 1; //LからRまでの間にある整数の個数
    ll ans;
    if(num >= value){
        ans = 0;
    }else{
        ans = 2019;
        for(ll j = L; j <= R; j++){
            for(ll k = j + 1; k <= R; k++){
            ll a = j * k;
            ans = min(ans, a % value);
            }
        }
    }
    cout << ans << endl;
    return 0;
}