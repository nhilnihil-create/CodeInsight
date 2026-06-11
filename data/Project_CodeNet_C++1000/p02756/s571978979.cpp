#include<bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main(){
  string s;
  cin >>s;
  int q;cin>>q;
  int t,f;
  char c;
  int tmp=0;
  for(int i=0;i<q;i++){
    cin >>t;
    if(t==1){
      tmp++;
    }
    else{
      cin >>f;
      cin >>c;
      if((f==1&&tmp%2==0)||f==2&&tmp%2==1){
        s=c+s;
      }
      else if((f==2&&tmp%2==0)||f==1&&tmp%2==1){
        s.push_back(c);
      }
    }
  }
  int size=s.size();
  if(tmp%2==0){
    for(int i=0;i<size;i++){
      cout<<s.at(i);
    }
    cout <<endl;
  }
  else{
    for(int i=size-1;i>=0;i--){
      cout <<s.at(i);
    }
    cout <<endl;
  }
}