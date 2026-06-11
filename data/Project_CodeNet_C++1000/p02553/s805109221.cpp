#include<bits/stdc++.h>
using namespace std;

      

int main(){
 long long int a,b,c,d;
 cin>>a>>b>>c>>d;
long long int ret=b*c;
long long int ret1=b*d;
long long int ret2=a*c;
long long int ret3=a*d;
long long int ans1=max(ret,ret1);
long long int ans2=max(ret2,ret3);
cout<<max(ans1,ans2);
  return 0;
    
}