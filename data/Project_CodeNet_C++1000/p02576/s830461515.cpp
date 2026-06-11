#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    int x,y,z,count=0;
    cin>>x>>y>>z;
    while(x>0)
    {
        x=x-y;
        count++;
    }
    cout<<z*count;
}