#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int i = 0, j = n - 1;
    while(j >= i) {
        while(j >= i && s[j] != 'R') {
            j--;
        }
        while(i < n && s[i] != 'W') {
            i++;
        }
        if(j < i) break;
        ans++;
        j--;
        i++;
    }
    cout << ans << endl;
}