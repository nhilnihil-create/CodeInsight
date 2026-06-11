#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

void insertionSort(vector<int> &A, int n, int g, int &cnt) {
    for (int i=g; i<n; ++i) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt ++;
        }
        A[j+g] = v;
    }
}

void shellSort(vector<int> &A, int n) {
    int cnt = 0;
    vector<int> G;

    G.push_back(1);
    for (int h=4; h<=n; h=h*3+1) {
        G.push_back(h);
    }
    int m = G.size();

    cout << m << endl;

    for (int i=m-1; i>=0; --i) {
        cout << (i==m-1 ? "" : " ") << G[i];
        insertionSort(A, n, G[i], cnt);
    }
    cout << endl;

    cout << cnt << endl;

    for (int i=0; i<n; ++i) {
        cout << A[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }
    shellSort(A, n);
    return 0;
}