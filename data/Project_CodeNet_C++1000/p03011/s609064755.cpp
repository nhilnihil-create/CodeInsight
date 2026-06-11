#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,sum=0;
    cin>>a>>b>>c;

   cout<<a+b+c-max(max(a,b),c)<<endl;

   exit(0);
}







