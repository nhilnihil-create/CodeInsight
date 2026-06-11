#include<bits/stdc++.h>

using namespace std;

void set_level(int room_l, int room_r, int level, vector<vector<int>>& a){
  if(room_r - room_l == 1) return;
  
  int room_m = (room_l + room_r) >> 1;
  for(int i = room_l; i < room_m; i++){
    for(int j = room_m; j < room_r; j++){
      a[i][j] = a[j][i] = level;
    }
  }
  
  ++level;
  set_level(room_l, room_m, level, a);
  set_level(room_m, room_r, level, a);
}

int main(){
  int N;
  cin >> N;
  
  vector<vector<int>> a(N, vector<int>(N, 0));
  
  set_level(0, N, 1, a);
  
  for(int i = 0; i < N - 1; i++){
    for(int j = i + 1; j < N - 1; j++){
      cout << a[i][j] << ' ';
    }
    cout << a[i][N - 1] << endl;
  }
  
  return 0;
}