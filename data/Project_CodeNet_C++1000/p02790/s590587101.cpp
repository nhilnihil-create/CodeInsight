#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int mn=min(a,b),mx=max(a,b);
    for(int i=0;i<mx;i++)
        cout<<mn;
    cout<<endl;
    return 0;
}

