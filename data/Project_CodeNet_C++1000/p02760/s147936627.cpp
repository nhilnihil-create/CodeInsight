#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> fri[100000];
vector<int> blo[100000];
int frindex[100000];
int frindexcounter[100000];
int blocounter, fricounter[100000];
int main() {
	
	//B
	int a[3][3];
	int i, j, k;
	for (i = 0; i < 3; i++) {
		for (j = 0;j< 3; j++) {
			cin >> a[i][j];
		}
	}
	int n;
	cin >> n;
	int b;
	for (i = 0; i < n; i++) {
		cin >> b;
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				if (a[j][k] == b) {
					a[j][k] = -1;
				}
			}
		}
	}
	for (i = 0; i < 3; i++) {
		if (a[i][0] * a[i][1] * a[i][2] == -1) {
			cout << "Yes" << endl;
			return 0;
		}
		if (a[0][i] * a[1][i] * a[2][i] == -1) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	if (a[0][0] * a[1][1] * a[2][2] == -1) {
		cout << "Yes" << endl;
		return 0;
	}
	if (a[0][2] * a[1][1] * a[2][0] == -1) {
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;
	return 0;
	//C
	/*int n, m;
	int s[3] = { -1,-1,-1 };
	int a, b;
	int i;
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		if (s[a - 1] == -1) {
			s[a - 1] = b;
		}
		else {
			if (s[a - 1] != b) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if (n == 3) {
		if (s[0] == 0) {
			cout << -1 << endl;
			return 0;
		}
		else if (s[0] == -1) {
			a = 100;
		}
		else {
			a = s[0] * 100;
		}
		if (s[1] == -1) {
			
		}
		else {
			a = a + s[1] * 10;
		}
		if (s[2] == -1) {

		}
		else {
			a = a + s[2];
		}
	}
	else if (n == 2) {
		if (s[0] == 0) {
			cout << -1 << endl;
			return 0;

		}
		else if (s[0] == -1) {
			a = 10;
		}
		else {
			a = s[0] * 10;
		}
		if (s[1] == -1) {

		}
		else {
			a = a + s[1] * 1;
		}
	}
	else {
		if (s[0] == -1) {
			a = 0;
		}
		else {
			a = s[0];
		}
	}
	cout << a << endl;
	return 0;*/
	//D
	/*int n, m, k;
	cin >> n >> m >> k;

	int i, j, a, b;
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		fri[a - 1].push_back(b - 1);
		fri[b - 1].push_back(a - 1);
	}
	for (i = 0; i < k; i++) {
		cin >> a >> b;
		blo[a - 1].push_back(b - 1);
		blo[b - 1].push_back(a - 1);
	}

	for (i = 0; i < n; i++) {
		frindex[i] = -1;
		frindexcounter[i] = 0;
	}
	queue<int> que;
	int index = 0;
	for (i = 0; i < n; i++) {
		if (frindex[i] == -1) {
			frindex[i] = index;
			que.push(i);
			while (que.size()) {
				j = que.front(); que.pop();
				for (a = 0; a < fri[j].size(); a++) {
					if (frindex[fri[j][a]] == -1) {
						que.push(fri[j][a]);
						frindexcounter[index]++;
						frindex[fri[j][a]] = index;
					}
				}
			}
			index++;
		}
	}

	for (i = 0; i < n; i++) {
		blocounter = 0;
		for (j = 0; j < blo[i].size(); j++) {
			if (frindex[blo[i][j]] ==frindex[i]) {
				blocounter++;
			}
		}
		fricounter[i] = frindexcounter[frindex[i]] - fri[i].size() - blocounter;
		
	}
	for (i = 0; i < n; i++) {
		cout << fricounter[i] << ' ';
	}
	return 0;*/

}