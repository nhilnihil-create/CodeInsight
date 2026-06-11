#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

const int mod = 1e9+7;
const ll INF = 1e18;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> v(n);
    ll counter = 0;
    v[0]++;
    ll pot = 10;
    ll value = 0;
    for(ll i = n-1 ; i >= 0 ; i--){
        int digit =  s[i] - '0';
        value = (value + digit * pot )% 2019;
        pot = pot * 10 % 2019;
        counter += v[value];
        v[value]++;
    }
    cout << counter;
}
