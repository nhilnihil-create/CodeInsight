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
    int n,m,a; cin >> n >> m;
    int total = 0;
    for(int i = 0;i < m;i++){
        cin >> a; total+=a;
    }
    if(n - total >= 0){
        cout << n-total;
    }else{
        cout << -1;
    }
}
