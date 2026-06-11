#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,k;
    cin>>a>>b;
    k=(a+b)/2;
    if(abs(k-a)==abs(k-b))
        cout<<k<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;
}

