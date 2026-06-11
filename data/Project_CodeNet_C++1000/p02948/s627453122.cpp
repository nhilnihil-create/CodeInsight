#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

// void solve(int M, int N, std::vector<int> A, std::vector<int> B)
void solve(int N, int M, std::vector<std::vector<int>> vv)
{
  long long score = 0;
  std::priority_queue<int> pq;
  for (int i = 1; i <= M; i++)
  {
    for(const auto& v: vv[i]){
      pq.push(v);
    }
    if(!pq.empty())
    {
      score += pq.top();pq.pop();
    }
  }
  std::cout << score << std::endl;


}

int main(void)
{
  int M;
  int N;
  std::cin >> N;
  std::cin >> M;
  // std::vector<std::pair<int, int>> vec(N);
  std::vector<std::vector<int>> vv(M+1);
  for(auto i0 = 0; i0 < N; ++i0)
  {
    int a, b;
    std::cin >> a;
    std::cin >> b;
    if(a>M) continue;
    vv[a].push_back(b);
    // vec[i0]=(std::make_pair(a, b));
  }
  solve(N, M ,vv);
  return 0;
}
