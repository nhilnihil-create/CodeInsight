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
    string s; cin >> s; int ans = 0;
    for(int i = 0;i < s.length()-2;i++){
        if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') ans++;
    }
    cout << ans;
}
