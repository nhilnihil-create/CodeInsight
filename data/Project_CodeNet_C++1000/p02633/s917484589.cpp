#include<bits/stdc++.h>
using namespace  std;
int main()
{
    int x;
    cin>>x;
    for(int i=1;i<100000;i++)
    {
        if(i*x%360==0)
        {
            cout<<i<<endl;
            break;
        }
    }
}