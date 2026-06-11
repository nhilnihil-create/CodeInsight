#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> A(n-1);
  for(int i=0;i<n-1;i++){
    cin>>A.at(i);
  }
  vector<int> B(n,0);
  for(int i=0;i<n-1;i++){
    B.at(A.at(i)-1)++;
  }
  for(int i=0;i<n;i++){
    cout<<B.at(i)<<endl;
  }
}
