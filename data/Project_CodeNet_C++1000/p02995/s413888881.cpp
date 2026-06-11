#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    // 最大公約数を求める
    if(a%b==0) return b;
    else{
        return (gcd(b, a%b));
    }
}

ll lcm(ll a ,ll b){
    return a * b / gcd(a, b);
}

int main(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll sum = b - a + 1;
    ll c_cnt= b/c - a/c, d_cnt= b/d - a/d;
    ll cd = lcm(c, d);
    ll cd_cnt = b/cd - a/cd;
    
    if(a%c==0) c_cnt++;
    if(a%d==0) d_cnt++;
    if(a%cd==0) cd_cnt++;

    ll ans = sum - c_cnt -d_cnt + cd_cnt;
    cout << ans << endl;
    return 0;
    
}