#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int k,y; cin >> k >> y;
    if ((k * 500) >= y) cout << "Yes";
    else cout << "No";
    return 0;
}
