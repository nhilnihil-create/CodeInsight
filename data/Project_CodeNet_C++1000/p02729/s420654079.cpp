#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  int M;
  int sum = 0;
  cin>>N;
  cin>>M;
  if(N > 1){
    for(int i = (N - 1);i > 0;i--){
      sum += i;
    }
  }
  if(M > 1){
    for(int i = (M - 1);i > 0;i--){
      sum += i;
    }
  }
  cout<<sum<<'\n';
}