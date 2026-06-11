#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    ll n; 
    ll cnt = 0;
    ll base = 5;
    cin >> n;
    if(n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    n /= 2;
    while(base <= n){
        cnt += (n / base);
        base *= 5;
    }

    cout << cnt << endl;

    return 0;
}