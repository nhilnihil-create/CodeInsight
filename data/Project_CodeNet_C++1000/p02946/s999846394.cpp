#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,x;
    cin>>k>>x;
    if(x+k<=10000 && x-k>=-10000)
    {
        for(int j=x-k+1;j<x;j++)
            cout<<j<<" ";
        for(int i=x;i<k+x;i++)
            cout<<i<<" ";

        cout<<endl;
    }
    else
    {
        for(int i=-10000,j=0;j<=k;i++,j++)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;

}