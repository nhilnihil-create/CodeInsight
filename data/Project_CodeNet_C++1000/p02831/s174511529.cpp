#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    else return gcd(b, a%b);
}
ll lcm(ll a, ll b){
 return a/gcd(a, b)*b;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll ans = lcm(a, b);
    cout << ans << endl;
 }