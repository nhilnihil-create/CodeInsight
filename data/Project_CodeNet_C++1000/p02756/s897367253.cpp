#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<set>
#include<string>
#include<bitset>
#include<queue>
using namespace std;


int main() {
	string S;
	int Q;
	cin >> S >> Q;
	bool re = true; //trueなら偶数回
	string head;
	for (int i = 0; i < Q; i++) {	
		int T;
		cin >> T;
		switch (T) {
		case 1:
			//操作1
			re = !re;
			break;
		case 2:
			//操作2
			bool atama = true;
			int F;
			string C;
			cin >> F >> C;
			if (F == 2) atama = false;
			if (!re) atama = !atama;
			if (atama) {
				head += C;
			}
			else {
				S += C;
			}
			break;
		}
		
	}

	if (!re) {
		//反転操作
		reverse(S.begin(), S.end());
		cout << S+head << endl;
	}
	else {
		reverse(head.begin(), head.end());
		cout << head +S << endl;
	}
	
	return 0;
}