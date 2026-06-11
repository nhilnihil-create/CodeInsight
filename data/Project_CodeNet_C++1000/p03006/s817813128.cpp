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
long long x[50];
long long y[50];
int main(){
  int N;
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> x[i] >> y[i];
  }

  set <pair<long long, long long> > diffs;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i != j){
        diffs.insert(make_pair(x[i] - x[j], y[i] - y[j]));
      }
    }
  }

  int ans = N;
  for(auto it = diffs.begin(); it != diffs.end(); it++){
    int edge_no = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(i != j){
          if(make_pair(x[i] - x[j], y[i] - y[j]) == *it){
            edge_no ++;
          }
        }
      }
    }
    ans = min(ans, N - edge_no);
  }
  cout << ans << endl;
  return 0;
}
