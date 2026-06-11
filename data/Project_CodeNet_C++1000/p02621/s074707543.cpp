#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#define ll long long
#define add push_back
 
using namespace std; 

ll fact(ll n){
    ll answ = 1;
    for( int i = 1; i <= n; i++){
        answ *= i;
    }
    return answ;
}

ll c(ll n, ll m){
    return fact(n) / (fact(m) * fact(n - m));
}


int main() {

    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t;  t = 1; //cin >> t;
    while(t--){
        ll a; cin >> a;
        cout << a + a * a + a * a * a << endl;
    }
    return 0;
}