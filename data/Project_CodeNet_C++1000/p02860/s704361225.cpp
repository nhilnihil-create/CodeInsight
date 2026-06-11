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
    int n ;cin >> n;
    string s; cin >> s;
    string ans = "No";
    if(n % 2 == 0){
        //cout << s.substr(s.length()/2,s.length());
        if(s.substr(0,s.length()/2) == s.substr(s.length()/2,s.length())) ans = "Yes";
    }
    cout << ans;
}
