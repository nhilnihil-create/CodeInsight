#include <bits/stdc++.h>
#define ll long long
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

int main() { _
    ll n; cin >> n;
    string s;
    while(n != 0){
        n--;
        ll temp = n % 26;
        s += 'a' + temp;
        n /= 26;
    }
    for(ll i = s.size() - 1; i >= 0 ; i--){
        cout << s[i];
    }
}