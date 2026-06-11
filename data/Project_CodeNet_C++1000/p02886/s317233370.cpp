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
    int n ; cin >> n;
    vector<int> vec;
    for(int i = 0;i < n;i++){
        int x; cin >> x; vec.push_back(x);
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            ans += vec[i] * vec[j];
        }
    }
    cout << ans;
}
