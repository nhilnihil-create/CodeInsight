#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    ll ans = 0;
    bool g = (S.at(0) == '>');
    ll temp = 0;
    ll was = 0;

    for(ll i = 0; i < S.size(); i++) {
        if(S.at(i) == '>' && g) {
            temp++;
        } else if(S.at(i) == '<' && !g) {
            temp++;
        } else if(S.at(i) == '>' && !g) {
            ans += (temp - 1)*temp/2;
            was = temp;
            temp = 1;
            g = 1;
            //ans = max(was, temp);
        } else {
            ans += (temp - 1)*temp/2;
            ans += max(was, temp);
            temp = 1;
            g = 0;
        }
    }
    if(S.at(S.size() - 1) == '>') {
        ans += temp*(temp - 1)/2;
        ans += max(temp, was);
    } else {
        ans += temp*(temp + 1)/2;
    }
    cout << ans << endl;

    return 0;
}