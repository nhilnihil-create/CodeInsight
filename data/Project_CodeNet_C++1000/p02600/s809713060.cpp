#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,x;
    cin>>x;
    x-=400;
    i=8;
    while(x>=200)
    {
        x-=200;
        i--;
    }
    cout<<i;
}