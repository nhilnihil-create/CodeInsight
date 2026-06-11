#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string> A(N);
  vector<int> B(N);
  int sum=0,subsum=0;
  for(int i=0;i<N;i++){
    cin >> A.at(i) >> B.at(i);
    sum+=B.at(i);
  }
  string E;
  cin >> E;
  for(int i=0;i<N;i++){
    subsum+=B.at(i);
    if(A.at(i)==E){
      break;
    }
  }
  cout << sum-subsum << endl;
}
      
    