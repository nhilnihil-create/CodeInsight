#include<bits/stdc++.h>
using namespace std;
int main(){
long long int a,v;
  cin>>a>>v;
  long long int b,w;
  cin>>b>>w;
  long long int t;cin>>t;
  if(a==b)cout<<"YES"<<endl;
  else if(w>=v)cout<<"NO"<<endl;
  else {
    long long int z= abs(a-b)/(v-w);
      if(z<t)cout<<"YES"<<endl;
      else {
        if(z==t){
          if(abs(a-b)%(v-w)==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
      }
  }
}