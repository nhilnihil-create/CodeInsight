#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  while(cin>>h>>w&&h&&w){
    for(int i=1;i<=h;++i){
      for(int j=1;j<=w;++j){
	cout<<"#";
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}

