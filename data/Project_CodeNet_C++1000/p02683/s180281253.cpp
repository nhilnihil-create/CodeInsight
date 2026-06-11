#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include <vector>
using namespace std;

int main(){
  int N,M,X;cin>>N>>M>>X;
  vector<int> C(N);
 // vector<int,vector<int>> A(N,vector<int>(M));
  int A[N][M];
  for(int i=0;i<N;i++){
    cin>>C.at(i);
    for(int j=0;j<M;j++) cin>>A[i][j];
  }
  priority_queue<int,vector<int>,greater<int>> ans;
  
  
  for(int bit=0;bit<(1<<N);bit++){
    vector<int> S;
    for (int i = 0; i < N; ++i) {
      if(bit & (1<<i)){// 列挙に i が含まれるか
        S.push_back(i);
      }
    }
    int sum=0;
    int size=S.size();
    vector<int> unstM(M,0);
    for(int i=0;i<size;i++){
      sum +=C.at(S.at(i));
      //for(int j=0;j<M;j++) unstM.at(j)+=A.at(S.at(i)).at(j);
      for(int j=0;j<M;j++) unstM.at(j)+=A[S.at(i)][j];
    }
    bool can=true;
    for(int i=0;i<M;i++){
      if(unstM.at(i)<X){
        can=false;
        //bool can=false;
        break;
      }
    }
    if(can) ans.push(sum);
  }
  if(ans.empty()) cout<<-1<<endl;
  else cout<<ans.top()<<endl;
}