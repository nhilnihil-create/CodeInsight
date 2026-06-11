#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,p=0,q=0,i;
    string s,t;
    cin>>a>>b;
    for(i=0; i<b; i++)
    {
        p=p*10+a;
    }
    for(i=0; i<a; i++)
    {
        q=q*10+b;
    }
    s=to_string(p);
    t=to_string(q);

    if(s<=t)cout<<s<<endl;
    else
        cout<<t<<endl;





}
