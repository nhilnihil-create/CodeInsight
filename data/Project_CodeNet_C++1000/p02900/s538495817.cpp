#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


#define U_TYPE ll

U_TYPE gcd(U_TYPE a, U_TYPE b){
    return b != 0 ? gcd(b, a % b) : a;
}

int main(){
    ll A, B;
    cin >> A >> B;

    ll C = gcd(A, B);
    ll i;
    ll ans = 1;
    for(i = 2; i * i <= C; i++){
        if(C % i == 0){
            ans++;
        }
        while(C % i == 0){
            C /= i;
        }
    }
    if(C != 1){
        ans++;
    }

    cout << ans << endl;

    return 0;
}


