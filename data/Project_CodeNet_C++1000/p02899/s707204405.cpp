#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int N;
  cin >> N;
  vector<int> B(N);
  for(int i=0;i<N;i++){
    int A;
    cin >> A;
    B.at(A-1)=i+1;
  }
  for(int i=0;i<N;i++){
    cout << B.at(i);
    if(i==N-1){
      cout << endl;
    }
    else{
      cout << " ";
    }
  }
}   