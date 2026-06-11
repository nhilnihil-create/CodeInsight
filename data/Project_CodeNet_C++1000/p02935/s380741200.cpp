#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<int>vec(N);
  for (int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(), vec.end());
  double M=vec.at(0);
  for (int j=1;j<N;j++){
    M+=vec.at(j);
    M /= 2;
  }
  cout << M << endl;
}
