#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long a;
    long long m;
    int k=0;
    long double p;
    double b;
    cin>>a>>b;
    p=round(b*100);
    m=(a*p)/100;
    cout<<m<<endl;
    return 0;
}
