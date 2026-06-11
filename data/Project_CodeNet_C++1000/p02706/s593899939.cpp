#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; int M; cin>>N>>M;
  vector<int> S(M);
  for(int i=0; i<M; i++){
    cin>>S.at(i);
    N-=S.at(i);
  }
  if(N>=0)
    cout<<N<<endl;
  else cout<<-1<<endl;
}
