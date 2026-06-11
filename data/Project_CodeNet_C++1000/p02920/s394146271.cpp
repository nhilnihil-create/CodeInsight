#define _USE_MATH_DEFINES
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
#include <iomanip>

using namespace std;
long long S[1 << 18];
int main(void){
  int N;
  cin >> N;
  for(int i = 0; i < (1 << N); i++){
    cin >> S[i];
  }

  sort(S, S + (1 << N));
  reverse(S, S + (1 << N));

  priority_queue <int> pq;
  vector <int> buf;
  long long prev = S[0];
  for(int i = 0; i < N; i++){
    buf.push_back(i);
  }
  for(int i = 1; i < (1 << N); i++){
    if(prev != S[i]){
      for(int j = 0; j < buf.size(); j++){
        pq.push(buf[j]);
      }
      buf.clear();
    }
    if(pq.empty()){
      cout << "No" << endl;
      return 0;
    } else {
      auto left_time = pq.top();
      pq.pop();
      for(int j = 0; j < left_time; j++){
        buf.push_back(j);
      }
    }
    prev = S[i];
  }
  cout << "Yes" << endl;
  return 0;
}
