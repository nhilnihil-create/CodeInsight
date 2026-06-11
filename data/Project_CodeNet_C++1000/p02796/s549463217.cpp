#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<int, int>> P(N);
  int X, L;
  for(int i=0; i<N; i++){
    cin >> X >> L;
    P.at(i)=make_pair(X+L, X-L);
  }
  sort(P.begin(), P.end());
  int Ans=0;
  int Now=-1000000009;
  for(int i=0; i<N; i++){
    if(P.at(i).second>=Now){
      Ans++;
      Now=P.at(i).first;
    }
  }
  cout << Ans << endl;
}