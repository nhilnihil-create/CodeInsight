#include <bits/stdc++.h>

#include <fstream>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long long N, K;
  cin >> N >> K;
  vector<long long> tele(N);
  vector<bool> itta(N);
  for(int i = 0; i < N; i++){
    cin >> tele[i];
    tele[i]--;
  } 
  vector<long long> junban;
  int k = 0;
  int cnt = 0;
  for(cnt; cnt < K; cnt++){
    if(cnt == K - 1){
      cout << tele[k] + 1 <<endl;
      return 0;
    }
    if(itta[k]){
      break;
    }
    itta[k] = true;
    junban.emplace_back(k);
    k = tele[k];
  }
  int start;
  for(int i = 0; i < junban.size(); i++){
    if(junban[i] == k){
      start = i;
      break;
    }
  }
  K -= cnt;
  int roop = junban.size() - start;
  int nokori = K % roop;
  //cout << start <<  " " << junban.size() << " " << roop << " " << nokori <<endl;
  /*
  for(auto x: junban){
    cout << x << " ";
  }
  cout <<endl;
  //*/
  cout << junban[start + nokori] + 1 <<endl;
}
