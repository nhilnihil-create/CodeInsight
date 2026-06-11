#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int N,M;
  cin >> N >> M;
  vector<long long> a(M,0);
  vector<long long> Ans(N+1,-1);

  for(int i = 0; i < M; i++){
    cin >> a.at(i); 
  }

  for(int i = 0; i < M; i++){
    Ans.at(a.at(i)) = 0;
  }

  if(Ans.at(1) != 0){
    Ans.at(1) = 1;
  }

  if(2 <= N){

    if(Ans.at(2) != 0){
    Ans.at(2) = 1;
    Ans.at(2) += Ans.at(1);
  }

  }

  if(3<=N){

  for(int i = 3; i < N+1; i++){
    if(Ans.at(i) != 0){
    Ans.at(i) = (Ans.at(i-1) + Ans.at(i-2))%1000000007;
    }
  }

  }

    cout << Ans.at(N) << endl;

}
