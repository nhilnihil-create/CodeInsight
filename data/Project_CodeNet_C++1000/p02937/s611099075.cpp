#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T;
  cin>>S>>T;
  int64_t N=S.size(),M=T.size();
  vector<vector<int64_t>> p(26);
  for(int i=0;i<N;i++){
    int a=S[i]-'a';
    p[a].push_back(i);
  }
  vector<int> q(26);
  for(int i=0;i<26;i++){
    q[i]=p[i].size();
  }
  int64_t K=0,L=0;
  for(int i=0;i<M;i++){
    int a=T[i]-'a';
    if(q[a]==0){
      K=0,L=-1;
      break;
    }
    else{
      if(L>p[a][q[a]-1]){
        L=p[a][0];
        K++;
      }
      else{
        int b=lower_bound(p[a].begin(),p[a].end(),L)-p[a].begin();
        L=p[a][b];
      }
    }
    L++;
    if(L==N){
      K++;
      L=0;
    }
  }
  cout<<K*N+L<<endl;
}

