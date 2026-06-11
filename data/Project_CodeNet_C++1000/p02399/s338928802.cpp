#include<iostream>
#include<iomanip>

using namespace std;
int main()
{
    long a,b;
    cin>>a>>b;
    double z;
    long x = a/b;
    long y = a%b;
    z = (double)a/(double)b;
    cout<<x<<" "<<y<<" "<<fixed << setprecision(8)<<z<<endl;
    return 0;
}