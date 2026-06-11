#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int data[N];
  bool quiz;
  quiz=true;
  for(int i=0;i<N;i++){
    cin>>data[i];
  }
  for(int i=0;i<N;i++){
    if(data[i]%2==0){
      if(data[i]%3==0 || data[i]%5==0){
        quiz=true;
      }
      else{
        quiz=false;
        break;
      }
    }
  }
  if(quiz==true){
    cout<<"APPROVED"<<endl;
  }
  else{
    cout<<"DENIED"<<endl;
  }
}
