#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string S; cin >> S;
	vector<string>K;
	string T = "";
	for (int i = 0; i < S.size(); i++) {
		T.push_back(S.at(i));
		if (K.empty()){
			K.push_back(T);
			T = "";
		}
		else {
			if (K.back() != T) {
				K.push_back(T);
				T = "";
			}
		}
	}
	cout << K.size() << endl;
}