/**
 * Title: A - Weather Prediction
 * Url: https://atcoder.jp/contests/abc141/tasks/abc141_a
 */
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    string s; cin >> s;
    string ans;
    if(s=="Sunny") {
        ans = "Cloudy";
    } else if (s=="Cloudy") {
        ans = "Rainy";
    } else {
        ans = "Sunny";
    }
    cout << ans << endl;
    return 0;
}