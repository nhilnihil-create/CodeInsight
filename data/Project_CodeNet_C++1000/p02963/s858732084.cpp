#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;


int main(){
    ll s;   cin >> s;
    vector<ll> a(6, 0);
    a.at(2) = 1;
    a.at(3) = 1e+9;

    
    a.at(5) = (a.at(3)-s%a.at(3))%a.at(3);
    a.at(4) = (s+a.at(5))/a.at(3);
    
    for(auto x: a) cout << x << ' ';
    cout << endl;
}