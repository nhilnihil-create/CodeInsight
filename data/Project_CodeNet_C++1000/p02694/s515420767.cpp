#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,i,p=100,y=0;
    cin>>x;
    while(p<x)
    {
        p+=p/100;
        y++;
    }
    cout<<y<<endl;
}
