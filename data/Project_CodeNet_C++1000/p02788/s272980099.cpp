#include<iostream>
#include<algorithm>
#include<cstdint>
#include<map>
#include<queue>

int const MAXN = 2e5;

std::pair<int, int> mon[MAXN];
int N, D, A;

int main() {
  std::cin >> N >> D >> A; D += D;
  for(int i = 0; i < N; ++i) {
    int X, H; std::cin >> X >> H;
    mon[i] = std::make_pair(X, (H+A-1)/A);
  }
  std::sort(mon, mon+N);
 
  int64_t ans = 0, sum = 0; 
  std::queue<std::pair<int, int>> q;
  for(int i = 0; i < N; ++i) {
    while(!q.empty() && q.front().first < mon[i].first) {
      sum -= (int64_t)q.front().second;
      q.pop();
    }
    int c = mon[i].second;
    if(c <= sum) continue;
    c -= sum;
    q.push(std::make_pair(mon[i].first+D, c));
    sum += (int64_t)c;
    ans += (int64_t)c;
  }
  std::cout << ans << std::endl;
  return 0;
}
