#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double n, d; cin >> n >> d;
    double cnt = 0;
    while(n--)
    {
        double x, y; cin >> x >> y;
        double xi = x*x;
        double yi = y*y;
        double ans = sqrt(xi+yi);
        if(ans<=d) cnt++;
    }
    cout << cnt << endl;
 
    return 0;
}
 