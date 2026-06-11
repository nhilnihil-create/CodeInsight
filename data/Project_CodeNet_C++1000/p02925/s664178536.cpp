#include <bits/stdc++.h>
using namespace std;

vector<int> oneDay(vector<vector<int>> &order, vector<int> &before) {
  vector<int> erased;
  vector<int> used(order.size());

  for(auto& el : before) {
    if(used[el]) continue;
    int size1 = order[el].size();
    if(size1 == 0) {
      continue;
    }
    int opponent = order[el][size1-1] - 1;
    if(used[opponent]) {
      continue;
    }
    int size2 = order[opponent].size();
    if(size2 == 0) {
      continue;
    }
    int opponentOpponent = order[opponent][size2-1] - 1;

    if (opponentOpponent == el) {
      erased.emplace_back(el);
      erased.emplace_back(opponent);
      used[opponent] = true;
    }
  }

  return erased;
}

int main() {
  int N;
  cin >> N;
  vector<vector<int> > order(N, vector<int>(N-1));

  for(int i=0;i<N;i++) {
    for(int j=0;j<N-1;j++) {
      cin >> order[i][j];
    }
  }

  int days = 0;

  int left = N * (N-1) / 2;

  int times = 0;
  
  vector<int> before(N);
  iota(before.begin(), before.end(), 0);

  while(left > 0) {
    times++;
    bool can = true;
    vector<int> erased = oneDay(order, before);
    before.clear();
    if(erased.size() == 0) {
      can = false;
    } else {
      for(int i=0;i<erased.size();i++) {
        order[erased[i]].pop_back();
        if(order[erased[i]].size() != 0) before.emplace_back(erased[i]);
      }
    }
    left = left - (erased.size() / 2);

    if(!can || times > N*(N-1)/2) {
      days = -1;
      break;
    } else {
      days++;
    }
  }

  cout << days << endl;

  return 0;
}

