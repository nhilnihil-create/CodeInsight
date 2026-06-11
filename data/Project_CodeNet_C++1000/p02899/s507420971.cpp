#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i = 0;i < N;i++){
    cin>>A[i];
  }
  vector<int> rev(N);
  for(int i = 0;i < N;i++){
    rev[A[i] - 1] = i + 1;
  }
  for(int i = 0;i < N;i++){
    cout<<rev[i]<<'\n';
  }
  return 0;
}