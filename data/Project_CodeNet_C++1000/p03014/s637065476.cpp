#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int H,W;
  cin >> H >> W;

  vector<vector<int>> left(H, vector<int>(W,0));
  vector<vector<int>> right(H, vector<int>(W,0));
  vector<vector<int>> up(H, vector<int>(W,0));
  vector<vector<int>> down(H, vector<int>(W,0));

  vector<vector<char>> v(H, vector<char>(W));

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> v.at(i).at(j);
    }
  }

  auto check = [&H,&W](int i, int j){
    if(i < 0 || i >= H ) return false;
    if(j < 0 || j >= W ) return false;
    return true; 
  };

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(v.at(i).at(j) == '#'){
        continue;
      }
      if(check(i,j-1) && v.at(i).at(j-1) == '.'){
        left.at(i).at(j) = left.at(i).at(j-1) + 1;
      } 
      if(check(i-1,j) && v.at(i-1).at(j) == '.'){
        up.at(i).at(j) = up.at(i-1).at(j) + 1;
      } 
    }
  }

  for(int i = H-1; i >= 0; i--){
    for(int j = W-1; j >= 0; j--){
      if(v.at(i).at(j) == '#'){
        continue;
      }
      if(check(i,j+1) && v.at(i).at(j+1) == '.'){
        right.at(i).at(j) = right.at(i).at(j+1) + 1;
      } 
      if(check(i+1,j) && v.at(i+1).at(j) == '.'){
        down.at(i).at(j) = down.at(i+1).at(j) + 1;
      } 
    }
  }

  int max_val = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if(v.at(i).at(j) == '#') continue;

      int tmp_val = 1;
      tmp_val += left.at(i).at(j) + right.at(i).at(j);
      tmp_val += up.at(i).at(j) + down.at(i).at(j);

      max_val = max( tmp_val, max_val);
    }
  }
  cout << max_val << endl;

}
