#include<bits/stdc++.h>
using namespace std;
queue<long long> yui;
int main()
{
    int k;
    cin>>k;
    for(int i=1;i<10;i++) yui.push(i);
    while(--k)
    {
        long long x=yui.front();
        int y=x%10;
        yui.pop();
        for(int i=max(0,y-1);i<=min(9,y+1);i++)
        yui.push(x*10+i);
    }
    cout<<yui.front();
}