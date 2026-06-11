#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;


int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (auto &a : A) cin >> a;
  partial_sum(begin(A), end(A), begin(A));
  transform(begin(A), end(A), begin(A),
            [&](long long x) { return abs(2 * x - A.back()); });
  cout << *min_element(begin(A), end(A)) << endl;
}
