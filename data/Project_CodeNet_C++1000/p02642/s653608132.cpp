#include<iostream>
#include<vector>
#include<map>

using namespace std;
#define FOR(it,A) for(auto it = A.begin(); it != A.end(); it++)

int main() {
	int N;
	cin >> N;
	map<int,int> A;
	map<int,int>::iterator it1, it2;
	vector<int> overlapped;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		it1 = A.find(a);
		if(it1 == A.end()) A.insert(make_pair(a,0));
		else {
			overlapped.push_back(a);
		}
	}
	int count = 0;
	int gop; // 1부터 곱해나가 
	int k;
	FOR(it1, A) { // 작은 것
		// Ai가 A 
		// Aj가 B
		if (it1->second == 0) { //1이면 이미 누군가의 배수야 
			k = 0;
			gop = 2;
			while (!(k > A.rbegin()->first)) {
				k = it1->first * gop;
				it2 = A.find(k);
				if (it2 != A.end()) it2->second = 1;
				gop++;
			}
			
		}
	}
	FOR(it1, overlapped) {
		it2 = A.find(*it1);
		it2->second = 1;
	}

	FOR(it1, A) {
		if (it1->second == 0) count++;
	}
	cout << count << endl;
	return 0;
}