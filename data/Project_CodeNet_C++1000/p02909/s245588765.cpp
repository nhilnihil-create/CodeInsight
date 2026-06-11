#include <bits/stdc++.h>
using namespace std;

int main() {
    string ans;
    string S;
    cin >> S;
    if(S == "Sunny")
        ans = "Cloudy";
    if(S == "Cloudy")
        ans = "Rainy";
    if(S == "Rainy")
        ans = "Sunny";

    cout << ans << endl;
}