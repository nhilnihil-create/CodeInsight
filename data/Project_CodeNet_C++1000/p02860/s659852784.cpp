#include<bits/stdc++.h>
using namespace std;
int main()
{
    int f,n,m;
    cin>>n;
    m=n/2;
    f=n%2;
    string a,s,t;
    cin>>a;
    s=a.substr(0,m);
    t=a.substr(m,n-m);
    if(f==0)
    {
        if(s==t)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else
        cout<<"No"<<endl;
    //cout<<t<<" "<<s;
    return 0;
}

