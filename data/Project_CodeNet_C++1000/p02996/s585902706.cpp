#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;


int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> AB(N);
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		AB[i] = make_pair(b, a);
	}
	sort(AB.begin(), AB.end());
	//bool deadline = true;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += AB.at(i).second;
		if (sum > AB.at(i).first) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
