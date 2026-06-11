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
    int k;
    string s;
    cin >> k >> s;
    if(s.size() <= k) cout << s << endl;
    else cout << s.substr(0, k) << "..." << endl; 
    return 0;
}