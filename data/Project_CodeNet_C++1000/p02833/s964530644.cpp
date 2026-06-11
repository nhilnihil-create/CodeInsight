#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    if( n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }else{
        ll tmp = 5;
        while(tmp <= n){
            ans += ((n/2)/tmp);
            tmp *= 5;
        }
    }

    cout << ans << endl;
    return 0;
}