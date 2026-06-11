#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
   ll W, H, x, y;
   cin >> W >> H >> x >> y;
   cout << (W * H) / 2.0 << " ";
   if(x == W/2.0 && y == H/2.0) cout << 1 << endl;
   else cout << 0 << endl;
}