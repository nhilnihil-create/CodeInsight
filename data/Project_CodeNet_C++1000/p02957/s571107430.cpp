#include<bits/stdc++.h>
using namespace std;
#define nl cout<<'\n';
int main()
{
    int a,b,c,d;
    cin>>a>>b;
    c=(a+b)/2;
    if(abs(a-c)==abs(b-c))
    cout<<c;
    else
      cout<<"IMPOSSIBLE";
    nl;
    return 0;
}
