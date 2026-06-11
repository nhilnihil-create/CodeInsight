#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

signed main() {
    string a, b;
    cin >> a >> b;
    string x, y;
    for(int i = 0; i < (b[0] - '0'); i++) {
        x += a;
    }
    for(int i = 0; i < (a[0] - '0'); i++) {
        y += b;
    }
    cout << min(x, y);
}
