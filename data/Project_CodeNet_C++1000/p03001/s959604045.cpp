#include<bits/stdc++.h> 
using namespace std; 
  
int main() 
{
    long double w, h, x, y;
    cin >> w >> h >> x >> y;
    if(x == w / 2 && y == h / 2) {
        cout << fixed << setprecision(9) << (w * h) / 2 << ' ' << 1;
    } else {
        cout << fixed << setprecision(9) << (w * h) / 2 << ' ' << 0;
    }
    return 0;
} 
