#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    double pi = 3.14159265358979323846;
    ll a, b, h, m;
    cin >> a >> b >> h >> m;
    double minutes = h*60+m;

    double angle =fabs((60*h - 11*m) * pi / 360);
    double ans = sqrt(a*a+b*b - 2 *a*b*cos(angle));
   cout.setf(ios::fixed);
    cout << setprecision(16) << ans << endl;
    return 0;
}



