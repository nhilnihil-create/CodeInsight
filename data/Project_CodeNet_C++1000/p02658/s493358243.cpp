#include <bits/stdc++.h>
using namespace std; 

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  long long sum=1;
  for(int i=0;i<N;i++){
    if(A.at(i)==0){
      cout << 0 << endl;
      return 0;
    }
    if(sum>1000000000000000000/A.at(i)){
      cout << -1 << endl;
      return 0;
    }
    sum*=A.at(i);
  }
  cout << sum << endl;
}
    
  