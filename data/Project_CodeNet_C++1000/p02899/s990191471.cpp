#include <iostream>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;
	map<int, int> m;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		m[tmp] = i;
	}

	for(auto itr = m.begin(); itr != m.end(); itr++) {
		cout << itr->second << " ";
	}
	cout << endl;

	return 0;
}