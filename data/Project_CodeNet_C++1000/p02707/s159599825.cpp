#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  vector<int> vec(N-1);
  vector<int> ans(N); 
  for(int i=0;i<N-1;i++){
    cin >>vec[i];
    ans[vec[i]-1]++;
  }
  for(int i=0;i<N;i++){
    cout << ans[i] <<endl;
  }
}