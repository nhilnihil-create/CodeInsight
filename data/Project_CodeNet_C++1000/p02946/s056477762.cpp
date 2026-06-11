#include<bits/stdc++.h>

using namespace std;


int main(){
  int K, X;
  cin >> K >> X;
  
  if(K==1){
    cout << X << endl;
    return 0;
  }else{
    for(int i=X-(K-1); i<=X+(K-1); i++){
      cout << i << " ";
    }
    cout << endl;
  }
  

  return 0;
}