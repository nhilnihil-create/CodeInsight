#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<long long> S(N);
  long long K=0;
  for(int i=0; i<N; i++){
    cin>>S.at(i);
  }
  for(int i=1; i<N; i++){
    if(S.at(i-1)>S.at(i)){
      K+=S.at(i-1)-S.at(i);
      S.at(i)=S.at(i-1);
    }
    else continue;
  }
  cout<<K<<endl;
}