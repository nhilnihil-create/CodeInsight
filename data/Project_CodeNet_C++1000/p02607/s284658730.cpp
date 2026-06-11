#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,y,c=0;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>y;
        if(y%2!=0 && (i+1)%2!=0)
            c++;
    }
    cout<<c;
}