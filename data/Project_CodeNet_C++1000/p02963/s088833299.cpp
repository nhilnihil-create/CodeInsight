#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    ll s;
    cin >> s;
    int y2 = (s+1000000000-1)/1000000000;  
    int y1 = 1000000000*y2-s;
    cout << "0 0 " << 1000000000 << " " << y1 << " "<< 1 << " " << y2 << " " << endl;
    return 0;
}