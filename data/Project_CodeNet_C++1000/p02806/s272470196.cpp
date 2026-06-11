#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  vector<int> T(N);
  for(int i=0; i<N; i++){
    cin >> S.at(i) >> T.at(i);
  }
  string X;
  cin >> X;
  int P;
  for(int i=0; i<N; i++){
    if(S.at(i)==X){
      P=i;
    }
  }
  int Ans=0;
  for(int i=P+1; i<N; i++){
    Ans+=T.at(i);
  }
  cout << Ans << endl;
}