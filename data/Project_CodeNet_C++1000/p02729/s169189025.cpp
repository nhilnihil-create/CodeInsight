#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n,m,s,r;
    cin>>n>>m;
    s=(n*(n-1))/2;
    r=(m*(m-1))/2;
    cout<<(s+r)<<endl;
    return 0;
}