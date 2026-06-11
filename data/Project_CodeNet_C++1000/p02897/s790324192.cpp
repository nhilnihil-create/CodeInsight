#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n, c=0, i;
    double d;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        if(i%2!=0)
            c++;
    }
    d=static_cast<double>(c) / (double)(n);

    cout<<fixed<<setprecision(10)<<d<<endl;

     return 0;
}
