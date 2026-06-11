#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int N = 105;
int main() {
	int n, t;
	cin >> n >> t;
	list<int> L;
	list<int>::iterator it, min;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		L.push_back(x);		
	}	
	vector<int>v;
	while (v.size() != t)
	{
		min = L.begin();
		for (it = L.begin(); it != L.end(); it++) {
			if (*it <= *min)
				min = it;
		}
		v.push_back(*min);
		L.erase(min);
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	cout << sum << endl;
	return 0;
}