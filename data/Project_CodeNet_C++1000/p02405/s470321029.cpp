#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int H = -1, W = -1;
	vector<pair<int,int> > inputs;

	while(true) {
		cin >> H >> W;
		if(H == 0 && W == 0) break;
		else inputs.push_back(pair<int,int>(H,W));
	}

	vector<pair<int,int> >::iterator it = inputs.begin();
	while(it != inputs.end()) {
		//	cout << (*it).first << ", " << (*it).second << endl;
		for(int i = 0; i < (*it).first; ++i) {
			for(int j = 0; j < (*it).second; ++j) {
				if(j%2==i%2) cout << "#";
				else cout << ".";
			}
			cout << endl;
		}
		cout << endl;
		++it;
	}
	return 0;
}