#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int N;
  
  cin>>N;
  vector<string> S(N);

rep(i,N){cin>>S.at(i);}
  sort(S.begin(), S.end());
  

  
   map<string, int> score;
int count=1,flg=1;
  rep(i,N-1){if(S.at(i+1)==S.at(i)){count++;}else{score[S.at(i)]=count;flg=max(flg,count);count=1;}}
  score[S.at(N-1)]=count;flg=max(flg,count);
  

  for (auto p : score) {
  auto k = p.first;
  auto v = p.second;
    if(v==flg){cout << k << endl;}
  }
}  