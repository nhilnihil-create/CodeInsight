#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

using ipair = pair<ll,ll>;

ll INF = 1e16+7;

bool operator>(const ipair a,const ipair b){return a.first > b.first;}


int main(){

  int N, M;
  cin >> N >> M;

  priority_queue<ipair> q;

  rep(i, N){
    int a, b;
    cin >> a >> b;

    q.push(make_pair(-a, b));
  }

  ll ans = 0;
  priority_queue<int> checked;


  rep(i, M){
    int remain_day = i+1;
    int q_max=-1;
    int checked_max=-1;

    while(remain_day >= -q.top().first && !q.empty()){
      checked.push(q.top().second);
      q.pop();
    }

    if(!checked.empty()){
      // cout << checked.top() << endl;
      ans += checked.top(); checked.pop();
    }
  }

  cout << ans << endl;

  return 0;
}
