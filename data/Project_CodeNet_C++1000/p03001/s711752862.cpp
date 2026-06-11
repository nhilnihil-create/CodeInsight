#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 long long w,h,x,y;
    cin >> w >> h >> x >> y;
    
    
    if(x == (double)w*0.5 && (double)y == h*0.5) {
     cout << (double)w*h*0.5 << ' ' << 1;
    }
    else {
     cout << (double)w*h*0.5 << ' ' << 0;}
}