#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;

	vector<int> a(s.size()+1,-1);

	if (s[0] == '<') { a[0] = 0; }
	if (s[s.size() - 1] == '>') { a[s.size()] = 0; }
	for (int i = 0; i < s.size()-1; i++) {

		if (s[i] == '>' && s[i + 1] == '<') {
			a[i + 1] = 0;
		}
	}

	for (int i = 0; i <= s.size(); i++) {
		if (a[i] == 0) {
			//右に行く
			int j = 0;
			while (s[i + j] == '<' && i+j+1<s.size()+1) {
				a[i + j + 1] = max(a[i+j+1],a[i + j] + 1);
				j++;
			}
			//左に行く
			j = 0;
			if (i != 0) {
				while (s[i + j - 1] == '>' && i + j  >= 0) {
					a[i + j - 1] = max(a[i + j - 1], a[i + j] + 1);
					j--;
					if (i + j == 0) { break; }
				}
			}
		}
	}

	//for (int i = 0; i <= s.size(); i++) {
	//	cout << a[i] << " ";
	//}

	cout << accumulate(a.begin(),a.end(),0LL) << endl;

	return 0;

}