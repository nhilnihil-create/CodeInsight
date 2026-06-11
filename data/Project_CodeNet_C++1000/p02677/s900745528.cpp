#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double PI=acos(-1.0);

int A,B,H,M;
void input()
{
    cin>>A>>B>>H>>M;
}

void solve()
{
    double deg=abs(60.0*H-11.0*M)/2.0;
    double ans=1.0*(A*A+B*B)-2.0*A*B*cos(deg/180*PI);
    cout<<fixed<<setprecision(10)<<sqrt(ans)<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}