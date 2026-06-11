#include <bits/stdc++.h>
using namespace std;

int main(){
long long a,v,b,w,t;
  cin>>a>>v>>b>>w>>t;
  if(w>v){
cout<<"NO"<<endl;
  }
 else if(abs(v*t-w*t)>=abs(a-b)){
cout<<"YES"<<endl;
  }else{
cout<<"NO"<<endl;
  }
     }
