#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,count=0;
  cin >> N >> K;
  vector<int> num(N);
  for(int i=0;i<K;i++){
    int D;
    cin >> D;
    for(int i=0;i<D;i++){
      int A;
      cin >> A;
      num.at(A-1)++;
    }
  }
  for(int i=0;i<N;i++){
    if(num.at(i)==0){
      count++;
    }
  }
  cout << count << endl;
}
  
  