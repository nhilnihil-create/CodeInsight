#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a=a+d-1;
    c=b+c-1;
    a=a/d;
    c=c/b;
    if(a<c)
      cout<<"No";
    else
      cout<<"Yes";
    nl;
    return 0;
}
