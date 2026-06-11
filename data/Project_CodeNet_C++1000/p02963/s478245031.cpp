#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    ll s;
    cin >> s;
    ll l = 1000000000;
    if(s % l == 0){
        ll a = s / l;
        cout << "0 0 0 " << l << ' ' << a << " 0" << endl;
    }else{
        ll x = (s + l - 1) / l;
        cout << "0 0 1 1000000000 " << x << ' ' << l - s % l << endl;
    }
    
}