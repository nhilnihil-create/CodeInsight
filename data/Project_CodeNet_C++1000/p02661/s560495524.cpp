#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define input std::cin

using vector = std::vector<int>;
using lint = long long int;
using string = std::string;

int lowerbound (int k, vector& v) {
  return v[k-1];
}

int main() {
  int n; input >> n;
  vector start (n);
  vector end (n);
  for (int i=0; i<n; i++) {
	int a, b; input >> a >> b;
	start[i] = a; end[i] = b;
  }
  std::sort (start.begin(), start.end());
  std::sort (end.begin(), end.end());

  if (n % 2 != 0) {
	// n is odd
	int lambda = n/2;
	int atleast = end[lambda];
	int atmost = start[lambda];
	std::cout << atleast - atmost + 1 << std::endl;
  }
  else {
	// n is even
	int l1 = start[n/2-1];
	int r1 = end[n/2-1];
	int l2 = start[n/2];
	int r2 = end[n/2];
	int mr = (r1+r2);
	int ml = (l1+l2);
	std::cout << mr-ml+1 << std::endl;
  }
}

