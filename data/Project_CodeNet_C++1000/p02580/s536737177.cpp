#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
int h[300000];
int w[300000];
int main(){
  int H;
  int W;
  int M;
  cin >> H >> W >> M;

  for(int i = 0; i < M; i++){
    cin >> h[i] >> w[i];
  }

  map <int, int> h_count;
  map <int, int> w_count;

  for(int i = 0; i < M; i++){
    if(h_count.find(h[i]) != h_count.end()){
      h_count[h[i]] ++;
    } else {
      h_count[h[i]] = 1;
    }

    if(w_count.find(w[i]) != w_count.end()){
      w_count[w[i]] ++;
    } else {
      w_count[w[i]] = 1;
    }
  }

  int max_h_count = 0;
  int max_w_count = 0;
  for(auto it = h_count.begin(); it != h_count.end(); it++){
    max_h_count = max(max_h_count, it->second);
  } 
  for(auto it = w_count.begin(); it != w_count.end(); it++){
    max_w_count = max(max_w_count, it->second);
  }

  int ans = max_h_count + max_w_count - 1;
  set <int> max_h_set;
  for(auto it = h_count.begin(); it != h_count.end(); it++){
    if(it->second == max_h_count){
      max_h_set.insert(it->first);
    }
  }

  set <int> max_w_set;
  for(auto it = w_count.begin(); it != w_count.end(); it++){
    if(it->second == max_w_count){
      max_w_set.insert(it->first);
    }
  }

  int cross_count = 0;
  for(int i = 0; i < M; i++){
    if(max_h_set.find(h[i]) != max_h_set.end() && max_w_set.find(w[i]) != max_w_set.end()){
      cross_count ++;
    }
  }

  if(cross_count < max_h_set.size() * max_w_set.size()){
    cout << max_h_count + max_w_count << endl;
  } else {
    cout << max_h_count + max_w_count - 1 << endl;
  }
  return 0;
}
