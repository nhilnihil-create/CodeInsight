#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d,e,f,g,h,i;
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
  int N;
  cin>>N;
  vector<int> aa(N);
  for(int j=0;j<N;j++){
    cin>>aa.at(j);
  }
  for(int j=0;j<N;j++){
    if(aa.at(j)==a){
      a=0;
    }
    if(aa.at(j)==b){
      b=0;
    }
    if(aa.at(j)==c){
      c=0;
    }
    if(aa.at(j)==d){
      d=0;
    }
    if(aa.at(j)==e){
      e=0;
    }
    if(aa.at(j)==f){
      f=0;
    }
    if(aa.at(j)==g){
      g=0;
    }
    if(aa.at(j)==h){
      h=0;
    }
    if(aa.at(j)==i){
      i=0;
    }
  }
  int flag=0;
  if(a==0&&b==0&&c==0){
    flag=1;
  }
  if(d==0&&e==0&&f==0){
    flag=1;
  }
  if(g==0&&h==0&&i==0){
    flag=1;
  }
  if(a==0&&d==0&&g==0){
    flag=1;
  }
  if(b==0&&e==0&&h==0){
    flag=1;
  }
  if(c==0&&f==0&&i==0){
    flag=1;
  }
  if(a==0&&e==0&&i==0){
    flag=1;
  }
  if(c==0&&e==0&&g==0){
    flag=1;
  }
  if(flag==1){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}