#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t a,v;
  cin >>a>>v;
  int64_t b,w;
  cin>>b>>w;
  int64_t t;
  cin >>t;
  if(v<=w){
    cout <<"NO"<<endl;
    return 0;
  }
  if((double)abs(a-b)/(v-w)<=t){
    cout <<"YES"<<endl;
  }
  else
    cout <<"NO"<<endl;
}