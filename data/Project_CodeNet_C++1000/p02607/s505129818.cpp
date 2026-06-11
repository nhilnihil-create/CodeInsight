#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,A=0;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  for(int i=1; i<=N; i++){
    if(i%2 == 1 && vec.at(i-1)%2 == 1){
      A++;
    }
  }
  cout << A << endl;
}