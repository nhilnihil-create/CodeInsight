#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    double s = w*h/2.0;
    printf("%.10f ",s);
    if(w/2.0 == x && h/2.0 == y) cout << 1;
    else cout << 0;
}