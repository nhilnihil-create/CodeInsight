#include <bits/stdc++.h>
using namespace std; 

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  int B=0;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    B^=A.at(i);
  }
  for(int i=0;i<N;i++){
    int C=B^A.at(i);
    cout << C;
    if(i==N-1){
      cout << endl;
    }
    else{
      cout << " ";
    }
  }
}