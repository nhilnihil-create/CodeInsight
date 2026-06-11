#include<bits/stdc++.h>
using namespace std;

int main(){
  int K;
  cin >> K;
  vector<int> A(K);
  A.at(0)=7%K;
  for(int i=0;i<K-1;i++){
    A.at(i+1)=(10*A.at(i)+7)%K;
  }
  for(int i=0;i<K;i++){
    if(A.at(i)==0){
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
      