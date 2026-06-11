#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    ll n;
    cin >> n;
    
    ll y = 1;
    for(ll i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            y = i;
        }
    }
    //cout << y << endl;
    cout << n/y + y - 2 << endl;
    
    
    
    return 0;
}


