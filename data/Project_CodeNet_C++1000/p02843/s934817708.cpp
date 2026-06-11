#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int x;
    cin >> x;
    int mx = x/100;
    for(int i = 0; i <= mx; ++i) {
        int y = x-100*i;
        if(i >= 0 && y <= 5*i) {cout << 1 << endl; return 0;}
    }
    cout << 0 << endl;
    return 0;
}