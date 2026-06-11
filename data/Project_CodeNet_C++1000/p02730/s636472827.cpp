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
    string s; cin >> s;
    string r = s;reverse(r.begin(),r.end());
    string f = s.substr(0,s.length()/2);
    string rf = f;reverse(rf.begin(),rf.end());
    string l = s.substr(s.length()/2+1,s.length());
    string rl = l;reverse(rl.begin(),rl.end());
    string ans = "No";
    if(f == rf && l == rl && s == r) ans = "Yes";
    cout << ans;
}
