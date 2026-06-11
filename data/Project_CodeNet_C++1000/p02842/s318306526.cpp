#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;float p=1.08,x,s,q,f;
    cin>>n;
    x=n/p;
    s=ceil(x);
    q=ceil(x)*p;
    f=floor(q);
    if(n==f)
    {
        cout<<s;
    }
    else{
        cout<<":(";
    }


}
