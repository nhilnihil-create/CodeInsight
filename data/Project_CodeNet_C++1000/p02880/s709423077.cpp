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
    int n; cin >> n;
    string ans = "No";
    for(int i = 1;i <= 9;i++){
        for(int j = 1;j <= 9;j++){
            if(i * j == n) ans = "Yes";
        }
    }
    cout << ans;
}
