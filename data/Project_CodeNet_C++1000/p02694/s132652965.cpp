#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x,m=100,count=0;
    cin>>x;
    while(m<x)
    {
        m=m+m*0.01;
        count++;
    }
    cout<<count<<endl;
}
