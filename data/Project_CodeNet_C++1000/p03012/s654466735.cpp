#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;

int main() {
    int n; cin >> n; int a[n];
    int ans = 100000; int total = 0;int total1 = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        total += a[i];
    }

    for(int i = 0;i < n;i++){
        ans = min(abs(total-total1),ans);
        total1 += a[i];
        total -= a[i];
    }
    cout << ans;
    
    
}


