#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    int tmp=-1;
    cin>>a>>b;
    for (int i=1;i<=1009;i++)
    {
        int x=i*0.08;
        int y=i*0.1;
        if(x==a&&y==b)
        {
            tmp=i;
            break;
        }
    }
    cout<<tmp<<endl;
}