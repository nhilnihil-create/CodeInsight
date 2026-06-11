#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
  	cin >> n;
  	int x, y;
  	vector<int> v;
  	for (int i=1; i<=n; ++i) {
    	cin >> x >> y;
      	v.push_back(x-y);
    }
    if (v.end() != search_n(v.begin(), v.end(), 3, 0)) {
    	cout << "Yes";
    }	else {
    	cout << "No";
    }
  	return 0;
}