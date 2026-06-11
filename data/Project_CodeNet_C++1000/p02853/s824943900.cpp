#include <bits/stdc++.h>

using namespace std;
int aa[4]={300000,200000,100000,0};

int main() {
  int a,b;
  cin>>a>>b;if(a>=4){a=4;}if(b>=4){b=4;}
  a--;b--;
  int ans=0;
  ans+=aa[a];
  ans+=aa[b];
 if(a==b&&a==0){
     ans+= 
400000;}
cout<<ans;
}