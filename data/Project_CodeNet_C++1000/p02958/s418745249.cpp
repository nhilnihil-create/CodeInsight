#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    B.at(i)=i+1;
  }
  int count=0;
  for(int i=0;i<N;i++){
    if(A.at(i)!=B.at(i)){
      count++;
    }
  }
  bool a=false;
  if(count==0){
    cout << "YES" << endl;
  }
  else if(count!=2){
    cout << "NO" << endl;
  }
  else{
    sort(A.begin(),A.end());
    for(int i=0;i<N;i++){
      if(A.at(i)!=B.at(i)){
        a=true;
        break;
      }
    }
    if(!a){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }
}