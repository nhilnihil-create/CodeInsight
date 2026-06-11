#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  long long result = 0;
  map<string, int> countS;
  
  for (int i = 0; i < N; i++) {
  	string str;
    cin >> str;
    map<char, int> count;
    string tmp;
	int size = str.size();
    for (int j = 0; j < size; j++) {
    	count[str[j]] += 1;
    }
    for (auto p : count) {
  	  tmp += p.first;
  	  tmp += to_string(p.second);
    }
    if (countS[tmp] > 0) {
      	result += countS[tmp];
      	countS[tmp] += 1;
    } else {
    	countS[tmp] = 1;
    }
  }
  cout << result << endl;
}
