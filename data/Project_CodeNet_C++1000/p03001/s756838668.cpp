#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int h, w, x, y;
    cin >> w >> h >> x >> y;
    cout << fixed <<setprecision(12) << (long double)h * w / 2 << endl; 
    if(h % 2 == 0 && w % 2 == 0 && h / 2 == y && w / 2 == x) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
}