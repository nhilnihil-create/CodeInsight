#include<iostream>
using namespace std;
int main() {
	long long int a, b, n,k;
	cin >> n >> a >> b;
	if ((b - a) % 2 == 0) {
		cout << (b - a) / 2;
		return 0;
	}
	else {
		if (n - b < a - 1) {
			k = n - b;
		}
		else {
			k = a - 1;
		}
		cout << k + 1 + (b - a - 1) / 2;
		return 0;
	}
	/*
	int n,i,j;
	cin >> n;
	if (n == 2) {
		cout << -1;
	}else if(n==3){
		cout << ".aa\n";
		cout << "b..\n";
		cout << "b..";
	}
	else if (n % 4 == 0) {
		cout << "aacd";
		for (i = 5; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "bbcd";
		for (i = 5; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "cdaa";
		for (i = 5; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "cdbb";
		for (i = 5; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		for (j = 4; j < n; j++) {
			for (i = 0; i < j-(j % 4); i++) {
				cout << ".";
			}
			if(j% 4==0){
				cout << "aacd";
			}
			else if (j % 4 == 1) {
				cout << "bbcd";
			}
			else if (j % 4 == 2) {
				cout << "cdaa";
			}
			else if (j % 4 == 3) {
				cout << "cdbb";
			}
			for (i = j - (j % 4) + 3; i < n-1; i++) {
				cout << ".";
			}
			cout << "\n";
		}
	}
	else if (n % 4 == 1) {
		cout << "..abc";
		for (i = 6; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "..abc";
		for (i = 6; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "aadde";
		for (i = 6; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "bbe.e";
		for (i = 6; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "ccedd";
		for (i = 6; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		for (j = 5; j < n; j++) {
			for (i = 0; i < (j - 1) - ((j - 1) % 4) + 1; i++) {
				cout << ".";
			}
			if ((j - 1) % 4 == 0) {
				cout << "aacd";
			}
			else if ((j - 1) % 4 == 1) {
				cout << "bbcd";
			}
			else if ((j - 1) % 4 == 2) {
				cout << "cdaa";
			}
			else if ((j - 1) % 4 == 3) {
				cout << "cdbb";
			}
			for (i = (j - 1) - ((j - 1) % 4) + 4; i < n - 1; i++) {
				cout << ".";
			}
			cout << "\n";
		}
	}
	else if (n % 4 == 2) {
		cout << ".aabaa";
		for (i = 7; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "a..b.b";
		for (i = 7; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "a..aab";
		for (i = 7; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "baa..a";
		for (i = 7; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "b.b..a";
		for (i = 7; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "aabaa.";
		for (i = 7; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";

		for (j = 6; j < n; j++) {
			for (i = 0; i < (j - 2) - ((j - 2) % 4) + 2; i++) {
				cout << ".";
			}
			if ((j - 2) % 4 == 0) {
				cout << "aacd";
			}
			else if ((j - 2) % 4 == 1) {
				cout << "bbcd";
			}
			else if ((j - 2) % 4 == 2) {
				cout << "cdaa";
			}
			else if ((j - 2) % 4 == 3) {
				cout << "cdbb";
			}
			for (i = (j - 2) - ((j - 2) % 4) + 5; i < n - 1; i++) {
				cout << ".";
			}
			cout << "\n";
		}
	}
	else if (n % 4 == 3) {
		cout << "a..bbaa";
		for (i = 8; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "ac..cc.";
		for (i = 8; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "bc.aa..";
		for (i = 8; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "b.b...b";
		for (i = 8; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "..b..cb";
		for (i = 8; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << ".cc..ca";
		for (i = 8; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		cout << "aabb..a";
		for (i = 8; i <= n; i++) {
			cout << ".";
		}
		cout << "\n";
		for (j = 7; j < n; j++) {
			for (i = 0; i < (j - 3) - ((j - 3) % 4) + 3; i++) {
				cout << ".";
			}
			if ((j - 3) % 4 == 0) {
				cout << "aacd";
			}
			else if ((j - 3) % 4 == 1) {
				cout << "bbcd";
			}
			else if ((j - 3) % 4 == 2) {
				cout << "cdaa";
			}
			else if ((j - 3) % 4 == 3) {
				cout << "cdbb";
			}
			for (i = (j - 3) - ((j - 3) % 4) + 6; i < n - 1; i++) {
				cout << ".";
			}
			cout << "\n";
		}
	}
	return 0;*/
}