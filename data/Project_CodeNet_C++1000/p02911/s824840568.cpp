#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K,Q;cin>>N>>K>>Q;
  vector<int> A(Q);
  for(int i=0;i<Q;i++) cin>>A.at(i);
  map<int,int> score;
  for(int i=1;i<=N;i++) score[i]=K-Q;
  for(int i=0;i<Q;i++) score[A.at(i)]++;
  for(int i=1;i<=N;i++){
    if(score.at(i)>0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}




