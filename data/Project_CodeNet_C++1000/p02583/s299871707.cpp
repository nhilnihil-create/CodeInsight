#include <bits/stdc++.h>
using namespace std; 

int main(){
  int N;
  cin >> N;
  vector<int> L(N);
  for(int i=0;i<N;i++){
    cin >> L.at(i);
  }
  long long count=0;
  for(int i=0;i<N-2;i++){
    for(int j=i+1;j<N-1;j++){
      for(int k=j+1;k<N;k++){
        long long A=L.at(i),B=L.at(j),C=L.at(k);
        if(A==B || B==C || C==A){
          continue;
        }
        if(A<B+C && B<C+A && C<A+B){
          count++;
        }
      }
    }
  }
  cout << count << endl;
}         