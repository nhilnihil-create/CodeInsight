#include <iostream>
#include <vector>
 
// Solution: from workding days point of view, for a single working day, there
// is a range it can be scheduled on, if this range is 1 then that day is
// required to work. We can greedy fill the working days to find out the ranges.
std::vector<int> CalculateDaysBoundToWork(const int M, const int N, const int K,
                                          const std::string& calendar) {
  // The earliest and latest possible days for each of the working days.
  std::vector<int> earliest(M, -1), latest(M, -1);
  // Greedy approach to fill working days forwards.
  int x = 0;
  for (int i = 0; i < N; ++i) {
    if (calendar[i] == 'o') {
      earliest[x++] = i;
      i += K;
    }
    if (x >= M) break;
  }
  // Greedy approach to fill working days backwards.
  x = M - 1;
  for (int i = N - 1; i >= 0; --i) {
    if (calendar[i] == 'o') {
      latest[x--] = i;
      i -= K;
    }
    if (x < 0) break;
  }
  // A day is required to work iff there exists work day cannot be both earlier
  // and later than the given day.
  std::vector<int> results;
  for (int i = 0; i < M; ++i) {
    if (earliest[i] != -1 && earliest[i] == latest[i]) {
      results.push_back(earliest[i]);
    }
  }
  return results;
}
 
int main() {
  int M, N, K;
  std::cin >> N >> M >> K;
  std::string calendar;
  std::cin >> calendar;
  const std::vector<int> res = CalculateDaysBoundToWork(M, N, K, calendar);
  for(const int i : res) {
    std::cout << i + 1 << "\n";
  }
  return 0;
}