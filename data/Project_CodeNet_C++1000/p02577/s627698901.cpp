#include <bits/stdc++.h>          
using namespace std;        
typedef long long ll;       

int main() {
    string S;
    cin >> S;
    ll NS = S.size();
    vector<int> N(NS);
    for (ll i=0; i<NS; i++) {
        N[i] = S[i]-'0';
    }
    ll count = 0;
    for (ll i=0; i<NS; i++) {
        count += N[i];
    }
    string ans = "No";
    if (count%9 == 0) {
        ans = "Yes";
    }
    cout << ans << endl;
}