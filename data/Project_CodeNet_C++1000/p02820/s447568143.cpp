#include <bits/stdc++.h>
using namespace std;
int getScore(char m, int R, int S, int P){
  if(m=='r') return R;
  else if(m=='s') return S;
  else if(m=='p') return P;
  else return 0;
}
char getMyHand(int i, char t, string T, string M, int K){
  if(i>=K && T[i]==T[i-K] && M[i-K]!='a') return 'a';
  if(t=='r') return 'p';
  else if(t=='s') return 'r';
  else return 's';
}
int main(){
  int N, K, R, S, P; cin >> N >> K >> R >> S >> P;
  string T; cin >> T;
  int score=0;
  string M;
  for(int i=0; i<N; i++){
    char t=T[i];
    M+=getMyHand(i, t, T, M, K);
    score+=getScore(M[i], R, S, P);
  }
  cout << score;
  return 0;
}