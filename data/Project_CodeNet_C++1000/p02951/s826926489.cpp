#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a,b,c;
 cin>>a>>b>>c;
 int ans = a-b;
int result = c-ans;
if(ans<c)
     cout<<result<<endl;
     else{cout<<0<<endl;}
}