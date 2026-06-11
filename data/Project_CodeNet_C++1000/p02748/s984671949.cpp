#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,M;
  cin >>A>>B>>M;
  vector<int> ref(A),mic(B),sum(M+1);
  vector<vector<int>> dis(M, vector<int>(3));
  for (int i=0;i<A;i++){
    cin >> ref.at(i);
  }
  for (int i=0;i<B;i++){
    cin >> mic.at(i);
  }
  for (int i=0;i<M;i++){
    for (int j=0;j<3;j++){
      cin >> dis.at(i).at(j);
    }
  }
  for (int i=0;i<M;i++){
    sum.at(i)=ref.at(dis.at(i).at(0)-1)+mic.at(dis.at(i).at(1)-1)-dis.at(i).at(2);
  }
  std::sort(ref.begin(),ref.end());
  std::sort(mic.begin(),mic.end());
  sum.at(M)=ref.at(0)+mic.at(0);
  std::sort(sum.begin(),sum.end());
  cout <<sum.at(0);
}