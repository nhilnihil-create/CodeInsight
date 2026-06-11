#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  for(int a=1;a<10;a++){
    for(int b=1;b<10;b++){
      if(a*b==N){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
}