#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;
const long long MOD = (long long)1e9 + 7;

int main(){
    ll a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    string ans;
    if (a < b){
        ans = ((a + v * t >= b + w * t)? "YES" : "NO");
    }else{
        ans = ((a - v * t <= b - w * t)? "YES" : "NO");
    }
    cout << ans << endl;
    return 0;
}
