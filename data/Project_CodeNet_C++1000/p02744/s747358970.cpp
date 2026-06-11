#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int n;
	cin >>n;

	queue<string>Q;

	Q.push("a");
	int count = 1;

	for (int i = 1; i < n;i++) {
		int c = count;
		while (c!=0) {
			string S = Q.front();
			Q.pop();
			c--;
			count--;
			int k = 0;
			for (int j = 0; j < i; j++) {
				k=max(k,S[j]-'a');
			}
			count += k+2;

			for (int j = 0; j <= k+1; j++) {
				char g='a'+j;
				string d = S + g;
				Q.push(d);
			}


		}
	}


	
	while (!Q.empty()) {
		cout << Q.front() << endl;
		Q.pop();
	}

	return 0;
}