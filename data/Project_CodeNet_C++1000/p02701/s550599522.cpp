#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin >> N;
  set<string> S;
  for(int i = 0; i < N; i++){
    string s; cin >> s;
    if(S.count(s))
      continue;
    else
      S.insert(s);
  }
  
  cout << S.size() << endl;
}