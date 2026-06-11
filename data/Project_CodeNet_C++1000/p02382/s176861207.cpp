#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int x[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    int d1=0, di=0, y, n;
    double d2=0, d3=0;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>x[i];
    }
    for(int i=0; i<n; i++) {
        cin>>y;
        d1+= abs(x[i]-y);
        d2+= (x[i]-y)*(x[i]-y);
        d3+= abs((x[i]-y)*(x[i]-y)*(x[i]-y));
        di = max(di, abs(x[i]-y));
    }
    cout<<d1<<'\n'<<sqrt(d2)<<'\n'<<pow(d3, 1.0/3.0)<<'\n'<<di<<'\n';
    return 0;
}