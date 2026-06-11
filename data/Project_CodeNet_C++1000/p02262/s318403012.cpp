#include <iostream>
#include <vector>
using namespace std;

int n;
int m = 0;
long long cnt;
vector<int> G;

void InsertionSort(int A[], int n, int g) {
    for (int i = g; i < n; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }
}

void ShellSort(int A[], int n) {
    G.clear();
    for (int i = 1; i <= n; i = i * 3 + 1) {
        G.push_back(i);
        m++;
    }
    for (int i = G.size() - 1; i >= 0; i--) {
        InsertionSort(A, n, G[i]);
    }
}

int main() {
	cin >> n;
	int A[n];
	cnt = 0;
	for (int i = 0; i < n; i++) cin >> A[i];
	ShellSort(A, n);
	cout << m << endl;
	for(int i = m - 1; i >= 0 ;i--) {
	    cout << G[i];
	    if (i < m) cout << " ";
	}
	cout << endl << cnt << endl;
	for (int i = 0; i < n; i++) cout << A[i] << endl;
}

