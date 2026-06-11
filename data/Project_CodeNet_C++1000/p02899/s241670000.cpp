#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

int main() {
    int n; cin >> n;
    multimap<int,int> m;
    for(int i = 1;i <= n;i++){
        int x; cin >> x;
        m.insert(make_pair(x,i));
    }
    for(auto x:m) cout << x.second << " ";
    
}
