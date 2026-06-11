#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<string> S;
  	int n;
  	string s;
  	cin >> n;
  	for (int i = 0; i < n; i++) {
      cin >> s;
      S.emplace(s);
    }
  	cout << S.size() << endl;
}