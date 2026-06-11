#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int d,r,a,b;
    double f,s,t;
    cin >> a >> b;
    s=a;
    t=b;
    d=a/b;
    r=a%b;
    f=s/t;
    cout<<d<<" "<<r<<" ";

    cout<<fixed<<setprecision(5)<<f<<endl;

    return 0;

}

