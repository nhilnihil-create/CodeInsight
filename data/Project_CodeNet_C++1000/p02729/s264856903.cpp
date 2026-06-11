#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;

    int r = n*(n-1)/2 + m*(m-1)/2 ;
    cout<<r;
    return 0;
}
