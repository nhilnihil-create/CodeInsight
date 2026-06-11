#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a,b,d=0,e,f;
    cin>>a>>b;
    d=(a+b)/2;
    e=a-d;
    f=b-d;
    if(e<0)
        e=e*(-1);
    if(f<0)
        f=f*(-1);
    if(e==f)
        cout<<d;
    else
        cout<<"IMPOSSIBLE";
}
