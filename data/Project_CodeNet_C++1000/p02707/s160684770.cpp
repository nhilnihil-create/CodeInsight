#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int>A(N+1,0);
  
  for(int i=2;i<=N;i++){
    int tmp;
    cin>>tmp;
    A[tmp]++;
  }
  
  for(int i=1;i<=N;i++){
    cout<<A[i]<<endl;
  }
  
  
}
