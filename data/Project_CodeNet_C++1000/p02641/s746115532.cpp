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
    int n,m; cin >> n >> m;
    set<int> s;
    for(int i = 0;i < m;i++){
        int x; cin >> x;
        s.insert(x);
    }
    
    if(m == 0){
        cout << n;
        return 0;
    }
    
    int ans = 200;
    int ans1 = 0;
    for(int i = 0;i <= 101;i++){
        if(s.count(i) == 0){
            if(ans > abs(n-i)){
                ans = abs(n-i);
                ans1 = i;
            }
        }
    }
    cout << ans1;
}

