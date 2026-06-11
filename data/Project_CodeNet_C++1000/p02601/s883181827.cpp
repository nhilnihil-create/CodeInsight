#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
    int r, g, b, x;
    cin >> r >> g >> b >> x;
    while(r >= g) g *= 2, --x;
    while(g >= b) b *= 2, --x;
    if(x >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}