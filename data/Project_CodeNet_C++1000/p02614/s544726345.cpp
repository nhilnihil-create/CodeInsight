#include <bits/stdc++.h>
using namespace std;

// count how many '1' is in the vector
int num(vector<vector<int>> v) {
  int sum = 0;
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v.at(0).size(); j++) {
      if(v.at(i).at(j) == 1) 
        sum++;
    }
  }
  return sum;
}

// change the numbers in a certain line of the vector into '2'
void change(int i, vector<vector<int>> &v) {
  if(i < v.size()) {
    for(int j = 0; j < v.at(0).size(); j++) {
      v.at(i).at(j) = 2;
    }
  }
  else {
    for(int j = 0; j < v.size(); j++) {
      v.at(j).at(i-v.size()) = 2;
    }
  }
  return;
}

// check the answer
int answer_check(int x, int k, vector<vector<int>> v) {
  vector<vector<int>> vcopy = v;
  int a = num(vcopy);
  if(a < k)
    return 0;
  
  else {
    int s = 0;
    if(a == k)
      s++;
    int sum = 0;
    for(int i = x; i < vcopy.size() + vcopy.at(0).size(); i++) {
      change(i,vcopy);
      sum += answer_check(i+1,k,vcopy);
      vcopy = v;
    }
    return sum + s;
  }
}
      
int main() {
  int H,W,K;
  cin >> H >> W >> K;
  vector<vector<int>> vec(H, vector<int>(W,0));
  for(int i = 0; i < H; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < W; j++) {
      if(s.at(j) == '#')
        vec.at(i).at(j) = 1;
    }
  }
  int ans = answer_check(0, K, vec);
  cout << ans << endl;
}