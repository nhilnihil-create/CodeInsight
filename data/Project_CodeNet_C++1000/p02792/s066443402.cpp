#include<bits/stdc++.h>

using namespace std;
typedef long long ll; 
int main(){
  ll N; cin >> N;
  vector<vector<ll>> v(10, vector<ll>(10, 0));
  
  for(int i = 1; i <= N; i++){
    string tmp = to_string(i);
    
    int head_num = tmp[0] - '0';
    int tail_num = tmp[tmp.size()-1] - '0';
    v[head_num][tail_num]++;
  }
  ll ans = 0;
  
  for(int i = 0; i <= 9; i++){
    for(int j = 0; j <= 9; j++){
      ans += v[i][j] * v[j][i];
    }
  }
  cout << ans << endl;
}