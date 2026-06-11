#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<string>>PS(M, vector<string>(2));
  
  for(int i=0; i<M; i++)cin >> PS.at(i).at(0) >> PS.at(i).at(1);
  
  int AC=0; int WA=0;int P;
  vector<int>F(N, 1);
  vector<int>count(N);
  for(int i=0; i<M; i++){
    P = stoi(PS.at(i).at(0))-1;
    if(F.at(P)){
      if(PS.at(i).at(1)=="WA")count.at(P)++;
      else{
        AC++;
        WA += count.at(P);
        F.at(P)=0;
      }
    }
  }
    
    cout << AC << " " << WA << endl;
}