#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

int main() {
    string s; cin >> s;
    int n = s.length();
    int a[1 << 17];
    for(int i=0; i<n; i++) {
        int ln = i;
        while(i + 1 < n && s[i] == s[i + 1]) i++;
        int len = i - ln + 1;
        if(s[i] == 'L') {
            a[ln] += (len + 1) / 2;
            a[ln - 1] += len / 2;
        }
        else {
            a[i] += (len + 1) / 2;
            a[i + 1] += len / 2;
        }
    }
    for(int i=0; i<n; i++) cout << a[i] << " ";
}
