#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<string> numbers;
    for(int i = 0; i < 1000; i++) {
        string x = to_string(i);
        if(x.size() == 1) {
            x = "00" + x;
        }
        else if(x.size() == 2) {
            x = '0' + x;
        }
        numbers.push_back(x);
    }
    int ans = 0;
    for(int i = 0; i < 1000; i++) {
        string x = numbers[i];
        int a = -1, b = -1, c = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == x[0]) {
                a = i;
                break;
            }
        }
        if(a == n-1) {
            continue;
        }
        for(int i = a+1; i < n; i++) {
            if(s[i] == x[1]) {
                b = i;
                break;
            }
        }
        if(b == n-1) {
            continue;
        }
        for(int i = b+1; i < n; i++) {
            if(s[i] == x[2]) {
                c = i;
                break;
            }
        }
        if(a != -1 && b != -1 && c != -1) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}