#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    float x,s,q,f;
    cin>>n;
    x=n/1.08;
    s=ceil(x);
    q=ceil(x)*1.08;
    f=floor(q);
    if(n==f)
    {
        cout<<s<<endl;
    }
    else{
        cout<<":("<<endl;
    }
    return 0;
}