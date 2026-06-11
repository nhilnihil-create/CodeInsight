#include<bits/stdc++.h>
using namespace std;
int main(){
  int X,Y;
  cin>>X>>Y;
  for(int i=0;i<=X;i++){
    int t=X-i;
    int asi=i*2+t*4;
    if(asi==Y){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}
