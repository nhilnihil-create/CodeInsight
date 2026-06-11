#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int A[1000000];
int n;
long long cnt;
int m;
vector<int> G;

void isort(int g)
{
	for (int i = g; i < n; i++) {
		int v = A[i];
		int j = i - g;
		while (j >= 0 && A[j] > v) {
			A[j + g] = A[j];
			j -= g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void ssort() 
{
	cnt = 0;
	for (int i = 1; i <= n; i = i * 3 + 1) {
		G.push_back(i);
	}
	for (int i = G.size() - 1; i >= 0; i--) {
		isort(G[i]);
	}


}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", A + i);
	}
	ssort();
	cout << G.size() << endl;
	for (int i = G.size() - 1; i>= 0; i--) {
		cout << G[i];
		if (i != 0) cout << " ";
		else cout << endl;
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		printf("%d\n", A[i]);
	}
	return 0;
}
