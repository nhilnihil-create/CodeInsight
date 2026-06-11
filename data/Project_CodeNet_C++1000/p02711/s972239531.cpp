#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  int num = 0;
  cin>>N;
  string S = to_string(N);
  for(int i = 0;i < S.size();i++){
    if(S[i] == '7'){
      cout<<"Yes"<<'\n';
      num = 1;
      break;
    }
  }
  if(num == 0){
    cout<<"No"<<'\n';
  }
}