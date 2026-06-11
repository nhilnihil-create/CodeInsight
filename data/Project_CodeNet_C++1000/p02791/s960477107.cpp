#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p;
	int i;
	for(i=0; i<n; i++){
		int x;
		cin >> x;
		p.push_back(x);
	}
	int count = 1, k = p[0];
	for(i=1; i<n; i++){
		if(p[i]<=k) count++;
		k = min(k, p[i]);
	}
	cout << count << "\n";
	return 0;
}
