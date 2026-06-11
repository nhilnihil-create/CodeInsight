#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  cin>>a;
  int b=0;
  int c=0;
  if(a.size()%2==1){
    b++;
  }
  else{
    for(int i=0;i<a.size()/2;i++){
      if(!(a.at(i*2)=='h'&&a.at(i*2+1)=='i')){
        b++;
      }
    }
  }
  if(b==0){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}