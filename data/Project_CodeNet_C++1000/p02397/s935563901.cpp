#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b&&(a||b))
    {
          if(a>b)
        cout<<b<<' '<<a;
    else cout<<a<<' '<<b;
    cout<<endl;
    }

}