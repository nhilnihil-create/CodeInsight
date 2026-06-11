#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


int main() {
    int a,b; cin >> a >> b;
    int ans = -1;
    for(int i = 1;i <= 1000;i++){
        if(floor(i * 0.08) == a && floor(i * 0.1) == b){
            ans = i;
            break;
        }
    }
    cout << ans;
}


