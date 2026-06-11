#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
  long long N;
  cin >> N;

  vector<long long> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  vector<long long> from_left(N);
  vector<long long> from_left_up(N);
  vector<long long> from_left_down(N);
  from_left[0] = a[0];
  for (int i = 1; i < N; ++i) {
    from_left[i] = a[i] + from_left[i - 1];
  }

  vector<long long> from_right(N);
  from_right[N - 1] = a[N - 1];
  for (int i = N - 2; i >= 0; --i) {
    from_right[i] = a[i] + from_right[i + 1];
  }

  long long min_diff = 1000000000000;
  int min_index = 0;
  for (int i = 0; i < N - 1; ++i) {
    long long diff = abs(from_left[i] - from_right[i + 1]);
    if (diff < min_diff) {
      min_index = i;
      min_diff = diff;
    }
  }

  cout << abs(from_left[min_index] - from_right[min_index + 1]) << endl;

  return 0;
}