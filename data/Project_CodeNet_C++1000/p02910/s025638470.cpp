#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){    
  string S;
  cin >> S;
  int Ans = 0;
  int N = S.size();
  if(N%2 == 0){
    for(int i = 0; i < N/2; i++){
      if(S.at(2*i) == 'R' || S.at(2*i) == 'U' || S.at(2*i) == 'D') Ans++;
      if(S.at(2*i+1) == 'L' || S.at(2*i+1) == 'U' || S.at(2*i+1) == 'D') Ans++;
    }
  }
  else{
    for(int i = 0; i < N/2; i++){
      if(S.at(2*i) == 'R' || S.at(2*i) == 'U' || S.at(2*i) == 'D') Ans++;
      if(S.at(2*i+1) == 'L' || S.at(2*i+1) == 'U' || S.at(2*i+1) == 'D') Ans++;
    }
    if(S.at(N-1) == 'R' || S.at(N-1) == 'U' || S.at(N-1) == 'D') Ans++;
  }
  if(Ans == N) cout << "Yes" << endl;
  else cout << "No" << endl;
}
