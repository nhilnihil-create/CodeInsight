#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int red = 0;
    for (auto& x : str) {
        if (x == 'R')
            red++;
    }
    int ans = 0;
    for (int i(0); i < red; ++i) {
        if (str[i] == 'W')
            ans++;
    }
    cout << ans << endl;
}