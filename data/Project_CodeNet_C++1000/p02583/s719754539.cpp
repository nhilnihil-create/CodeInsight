#include <iostream>
#include <vector>
using namespace std;

struct Triplet {
   int L1, L2, L3; 
};

bool isTriangle(const Triplet& t) {
	return (t.L1 + t.L2 > t.L3) &&
      	   (t.L1 + t.L3 > t.L2) &&
           (t.L2 + t.L3 > t.L1);
}

bool isDifferent(const Triplet& t) {
	return (t.L1 != t.L2) &&
      	   (t.L2 != t.L3) &&
           (t.L3 != t.L1);
}

const vector<Triplet> createFilteredTriplets(const vector<int>& sticks) {
  int sticks_size = sticks.size();
  vector<Triplet> triplets;
  for (int i = 0; i <= sticks_size - 3; ++i) {
    for (int j = i + 1; j <= sticks_size - 2; ++j) {
      for (int k = j + 1; k < sticks_size; ++k) {
        Triplet t = {sticks[i], sticks[j], sticks[k]};
        if (isDifferent(t) && isTriangle(t))
          triplets.push_back({sticks[i], sticks[j], sticks[k]});
      }
    }
  }
  return triplets;
}

int main() {
  int N, stick;
  vector<int> sticks;
  cin >> N;
  for (int i = 0; i < N; ++i) {
  	cin >> stick;
    sticks.push_back(stick);
  }
  const vector<Triplet>& triplets = createFilteredTriplets(sticks);
  printf("%d", triplets.size());
  return 0;
}