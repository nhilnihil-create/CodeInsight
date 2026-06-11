#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i;
    cin>>a>>b;
    for(i=0;i<max(a,b);i++)
        cout<<min(a,b);
    cout<<endl;
}
