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
#include <cmath>
#include <numeric>
using namespace std;
pair <long long, long long> XH[200000];
int main(){
  int N;
  long long D;
  long long A;
  cin >> N >> D >> A;
  for(int i = 0; i < N; i++){
    cin >> XH[i].first >> XH[i].second;
  }
  sort(XH, XH + N);

  queue <pair <long long, long long> > q;
  long long damage_sum = 0;
  long long ans = 0;
  for(int i = 0; i < N; i++){
    while(!q.empty() && q.front().first < XH[i].first){
      damage_sum -= q.front().second;
      q.pop();
    }

    long long cur_H = XH[i].second - damage_sum;
    if(cur_H > 0){
      int use_bomb_num;
      if(cur_H % A == 0){
        use_bomb_num = cur_H / A;
      } else {
        use_bomb_num = cur_H / A + 1;
      }
      ans += use_bomb_num;
      damage_sum += use_bomb_num * A;
      q.push(make_pair(XH[i].first + 2 * D, use_bomb_num * A));
    }
  }
  cout << ans << endl;
  return 0;
}
