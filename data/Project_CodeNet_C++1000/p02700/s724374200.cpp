#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, D;
  cin>>A>>B>>C>>D;

  int taka = (C+(B-1))/B;
  int aoki = (A+(D-1))/D;
  if(taka>aoki){
    cout<<"No"<<endl;
  }
  else{
    cout<<"Yes"<<endl;
  }
}