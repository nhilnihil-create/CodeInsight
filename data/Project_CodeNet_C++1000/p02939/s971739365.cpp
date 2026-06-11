#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string str;
    cin >> str;
    int i = 1;
    int ans = 1;
    int size = 1;
    string prev = str.substr(0, 1);
    while(i < str.size()) {
        if(str.substr(i, size) == prev) {
            if(i == str.size() - 1)
                break;
            size++;
        } else {
            prev = str.substr(i, size);
            ans++;
            i += size;
            size = 1;
        }
    }
    cout << ans << endl;
}