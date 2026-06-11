#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    double ans1 = double(a)*double(b) / 2; // rectangle can always be halved
    int ans2 = (x+x == a && y+y == b); // checks if (x,y) is the center
    cout << setprecision(6) << ans1;
    cout <<  " " << ans2 << endl;
    return 0;
}
