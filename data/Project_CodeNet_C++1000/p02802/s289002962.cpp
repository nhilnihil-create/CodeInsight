#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<bool> AC(N);
  vector<int> WA(N);
  for(int i = 0; i < M; i++){
    int p;
    string S;
    cin >> p >> S;
    if(AC[p-1]) continue;
    if(S == "AC"){
      AC[p-1] = true;
      continue;
    }else{
      WA[p-1] += 1;
    }
  }
  int ac = 0;
  int pn = 0;
  for(int i = 0; i < N; i++){
    if(!AC[i]) continue;
    ac += 1;
    pn += WA[i];
  }
  cout << ac << " " << pn << endl;

}
