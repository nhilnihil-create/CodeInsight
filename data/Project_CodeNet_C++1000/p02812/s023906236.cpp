#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int len; cin >> len;
    string a; cin >> a;
    int c = 0;
    for (int i = 2; i < len; i++) {
        if (a[i] == 'C' && a[i-1] == 'B' && a[i-2] == 'A') {
            c++;
            i += 2;
        }
    }
    cout << c;
    return 0;
}

