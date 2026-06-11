#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
int main(){
  int n;
  vector<int> P, Q;

  cin >> n;
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    P.push_back(tmp);
  }
  for(int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    Q.push_back(tmp);
  }

  bool change = false;
  for(int i = 0; i < n; i++){
    if(P[i] == Q[i]) {
      continue;
    } else if(P[i] > Q[i]) {
      change = true;
      break;
    } else {
      break;
    }
  }

  if(change) {
    int tmp;
    for(int i = 0; i < n; i++) {
      tmp = P[i];
      P[i] = Q[i];
      Q[i] = tmp;
    }
  }

  int cnt = 0;
  do {
    if(P == Q) {
      cout << cnt << endl;
      break;
    } else {
      cnt++;
    }
  } while(next_permutation(P.begin(), P.end()));

  return 0;
}
