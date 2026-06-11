#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b,i,ans,s;
    cin>>n>>a>>b;
    s=n/(a+b);
    i=n%(a+b);
    if(i>=a)
        cout<<s*a+a<<endl;
    else
        cout<<s*a+i<<endl;
}
