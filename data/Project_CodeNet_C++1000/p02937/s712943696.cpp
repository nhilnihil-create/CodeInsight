#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  string S,T;
  cin >> S;
  cin >> T;
  int S_size = S.size();

  S = S + S;


  map<char,vector<int>>  pos;
  for(int i = 0; i < S.size(); i++){
    pos[S[i]].push_back(i);
  }

  int ans = 0;
  int now_pos = 0;
  for(int i = 0; i < T.size(); i++){
    if(pos.count(T[i]) == 0){
      cout << -1 << endl;
      return 0;
    }
    if(i == 0){
      now_pos = pos[T[i]].at(0);
    } else { 
      // T[i]のリストの中で、now_posより大きいものを選ぶ
      int tmp_index = upper_bound(pos[T[i]].begin(), pos[T[i]].end(), now_pos) - pos[T[i]].begin(); 
      int tmp_pos = pos[T[i]].at(tmp_index);
      if(tmp_pos >= S_size){
        ans++;
        now_pos = pos[T[i]].at(0);
      } else { 
        now_pos = tmp_pos;
      }
    }
  }

  ll ret = (ll)(ans) * (ll)(S_size);
  ret += ll(now_pos) + 1;

  cout << ret << endl;


}
