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
    int k,n; cin >> k >> n;int diff = 0;
    int a[n];cin >> a[0];
    for(int i = 1;i < n;i++){
        cin >> a[i];
        diff = max(diff,abs(a[i]-a[i-1]));
    }
    diff = max(diff,abs(k-a[n-1])+a[0]);
    cout << k - diff;
}


