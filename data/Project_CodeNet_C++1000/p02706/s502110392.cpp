#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  int M;
  int a = 0;
  int sum = 0;
  cin>>N;
  cin>>M;
  for(int i = 0;i < M;i++){
    cin>>a;
    sum += a;
  }
  if(sum <= N){
    cout<<N - sum<<'\n';
  }else if(sum > N){
    cout<<-1<<'\n';
  }
}