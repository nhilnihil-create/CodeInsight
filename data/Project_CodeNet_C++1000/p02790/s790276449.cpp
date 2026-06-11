#include <bits/stdc++.h> 
using namespace std; 
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(void) {
    io;
    int a,b; cin >> a >> b;
    char achar = '0' + a, bchar = '0' + b;
    string astr, bstr;
    rep(i, a) bstr.push_back(bchar);
    rep(i, b) astr.push_back(achar);
    cout << ((astr < bstr) ? astr : bstr);
    return 0;
}