#include<iostream>
using namespace std;

int main()
{
    int x;cin>>x;
    int k=1;
    for(;;k++)
    if((k*x)%360==0) break;
    cout<<k;
    return 0;
}