#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    double r;
    cin>>r;
    cout<<r*r*M_PI<<' '<<2*r*M_PI<<'\n';
    return 0;
}