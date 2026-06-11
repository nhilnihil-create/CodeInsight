#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	string s; cin >> s;
	string past; past.push_back(s[0]);
	int n = s.size(), cnt = 1;

	for(int i = 1; i < n; i++) {
		if(past.size() == 2ul) {
			past = s[i];
			cnt++;
			continue;
		}

		if(past.front() != s[i]) {
			past = s[i];
			cnt++;
			continue;
		}

		if(i >= n - 1)continue;
		past.push_back(s[i + 1]);
		cnt++;
		i++;

	}
	cout << cnt << endl;

}