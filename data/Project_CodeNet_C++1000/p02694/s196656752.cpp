#include<bits/stdc++.h>
using namespace std;

int main()
{
 long long X;
 long long ans=100;
 cin>>X;
 int count=0;
 while(ans<X)
 {
     ans+=ans/100;
     count++;
     
 }
 cout<<count<<endl;
  
}
