#include <bits/stdc++.h>
using namespace std;

map<string, int> M;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n;
	for (int i =0; i < n; i++){
		cin >> s;
		M[s]++;
	}
	vector<pair<int, string>> vet;
	for (map<string, int>::iterator it = M.begin(); it != M.end(); it++){
		vet.push_back({it->second * -1, it->first});
	}
	sort(vet.begin(), vet.end());
	for (int i = 0; i < vet.size() && vet[i].first == vet[0].first; i++){
		cout << vet[i].second << endl;
	}
	return 0;
}