#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
     cin>>a>>b;
    int c=0;
    for(int i=0;i<=a;i++)
    {
        c=a-i;
        if(4*i+2*c==b)
        {
            cout<<"Yes"<<endl;
            exit(0);
    }
    }
    cout<<"No"<<endl;
}
