#include "bits/stdc++.h"

using namespace std;
int main() {
	int N;
	cin >> N;
	map<string, int> mp;
	vector<set<string>>V(200005);
	int vmax = 0;
	for (int n = 0;n<N;++n) {
		string str;
		cin >> str; 
		map<string, int>::iterator itr = mp.find(str);
		if (itr != mp.end()) {
			int n = itr->second; 
			mp[str]++;
			V[n].erase(str);
			V[n + 1].insert(str); 
			vmax = max(vmax, n + 1);
		}
		else {
			mp[str] = 1; 
			V[1].insert(str);
			vmax = max(1,vmax);
		}
	}
	int num = 1;
	for (auto itr = V[vmax].begin(); itr != V[vmax].end();itr++) {
		cout << *itr<<endl;
	}
	return 0;
}
