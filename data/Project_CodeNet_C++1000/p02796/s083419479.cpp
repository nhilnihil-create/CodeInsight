#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> end_pos;

bool comp(int i, int j) {
  return end_pos[i] < end_pos[j];
}

int main(int argc, char* argv[]) {
  int N;
  cin >> N;

  long long x[N];
  long long l[N];
  for (int i = 0; i < N; ++i)
    cin >> x[i] >> l[i];

  vector<long long> start_pos(N);
  end_pos.resize(N);
  vector<int> indices(N);
  for (int i = 0; i < N; ++i) {
    start_pos[i] = x[i] - l[i];
    end_pos[i] = x[i] + l[i];
    indices[i] = i;
  }

  sort(indices.begin(), indices.end(), comp);

  long long ret = 0;
  long long cur = -1000000000000;
  for (int i = 0; i < N; ++i) {
    int index = indices[i];
    if (cur <= start_pos[index]) {
      ++ret;
      cur = end_pos[index];
    }
  }

  cout << ret << endl;

  return 0;
}