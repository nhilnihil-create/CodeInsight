#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int m=abs(a-b)+1;
    if(m%2!=0)
    {
        a=min(a,b);
        cout<<a+((m+1)/2-1)<<endl;
    }
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
