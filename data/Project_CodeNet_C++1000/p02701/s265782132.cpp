#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	uint64_t N;
	cin >> N;
	vector<string>S(N);
	for (uint64_t i = 0; i <N ; ++i)
	{
		cin >> S[i];
	}
	sort(S.begin(), S.end());
	S.erase(unique(S.begin(), S.end()), S.end());

	cout << S.size() << endl;
	return 0;
}

