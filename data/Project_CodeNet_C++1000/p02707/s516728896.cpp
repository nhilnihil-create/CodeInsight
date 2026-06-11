#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> x(N+1);
  for (int i=2; i<N+1; i++){
    int A;
    cin>>A;
    x.at(A)++;
  }
  for (int i=1; i<N+1; i++){
    cout<<x.at(i)<<endl;
  }
}