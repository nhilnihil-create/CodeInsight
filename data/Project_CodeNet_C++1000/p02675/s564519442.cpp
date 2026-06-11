#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dl double long
#define rep(i, m, n) for(ll i = (ll)(m); i < (ll)(n); ++i)
#define rrep(i, m, n) for(ll i = (ll)(m); i > (ll)(n); --i)
const ll MOD = 1000000007;
const ll MMOD = 998244353;
const double pi = 3.14159265358979323846;

int main(void){
    int n;
    cin >> n;
    n %= 10;
    if(n == 3) cout << "bon" << endl;
    else if(n == 0 || n == 1 || n == 6 || n == 8) cout << "pon" << endl;
    else cout << "hon" << endl;
    
    return 0;
}