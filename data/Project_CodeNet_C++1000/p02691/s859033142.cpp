#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	unordered_map<int,int> m;
	long long int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(m.find((i - A[i])) != m.end())
		{
			count += m[i - A[i]];
		}
		m[(i +A[i])]++;
	}
	cout << count << endl;
	return 0;
}
