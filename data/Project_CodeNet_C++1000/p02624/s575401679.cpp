#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N+1);
  for(int i=1;i<N+1;i++){
    long long B=i;
    while(B<N+1){
      A.at(B)++;
      B+=i;
    }
  }
  long long sum=0;
  for(int i=0;i<N;i++){
    sum+=(i+1)*A.at(i+1);
  }
  cout << sum << endl;
}