#include <iostream>
#include <vector>
#include <climits>
#include <string>
#define input std::cin

using vector = std::vector<int>;
using lint = long long int;
using string = std::string;

int main() {
  string s, t;
  input >> s >> t;
  int min_change = INT_MAX;
  for (int i=0; i<=s.size()-t.size(); i++) {
	int changes = 0;
	for (int j=0; j<t.size(); j++) {
	  if (s[i+j] != t[j])
		changes ++;
	}
	if (changes < min_change)
	  min_change = changes;
  }
  std::cout << min_change << std::endl;
}

