#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y;
    cin>>x>>y;
    if(x>=1 && x<=9 && y>=1 && y<=9)
        cout<<x*y<<endl;
    else
        cout<<"-1"<<endl;
}

