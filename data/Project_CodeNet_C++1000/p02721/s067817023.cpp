#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculate(int& N, int& K, int& C, string& S)
{
  vector<int> o_position, work_day_min(K), work_day_max(K);
  for (int i = 0; i < N; i++)
    if (S[i] == 'o')
      o_position.push_back(i);
  int count = 0;
  for (int i = o_position[0]; i < N && count <= K; i++)
    if (S[i] == 'o'){
      work_day_min[count] = i;
      i += C;
      count++;
    }
  count = K - 1;
  for (int i = o_position[o_position.size() - 1]; i > 0 && count >= 0; i--)
    if (S[i] == 'o'){
      work_day_max[count] = i;
      i -= C;
      count--;
    }
  for (int i = 0; i < K; i++)
    if (work_day_min[i] == work_day_max[i])
      cout << work_day_min[i] + 1 << '\n';
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K, C;
  string S;
  cin >> N >> K >> C >> S;
  calculate(N, K, C, S);
  return 0;
}
