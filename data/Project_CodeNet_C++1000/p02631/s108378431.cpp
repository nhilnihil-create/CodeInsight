#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	
	int total_xor = 0;

	for(int i = 0; i < n; i += 2)
		total_xor ^= (v[i] ^ v[i+1]);
	
	for(int i = 0; i < n; i++)
		cout << (total_xor ^ v[i]) << ' ';

	return 0;
}