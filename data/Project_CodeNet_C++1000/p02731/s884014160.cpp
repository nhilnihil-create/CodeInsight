#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main()
{
    long double a;
    cin>>a;
    double ans=(a*a*a)/27;
    printf("%.10f",ans);
}