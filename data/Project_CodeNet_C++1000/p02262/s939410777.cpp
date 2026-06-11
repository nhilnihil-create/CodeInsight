#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long cnt;
vector<int> G;

void insertionSort(vector<int>& A, int g) {
    for (auto i = g; i < A.size(); i++) {
        int v = A[i];
        int j = i-g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(vector<int>& A) {
    cnt = 0;

    int i = 1;
    while (i <= A.size()) {
        G.push_back(i);
        i = 3*i + 1;
    }
    for (int i = G.size()-1; i >= 0; i--) {
        insertionSort(A, G[i]);
    }
}


int main(void) {
    int n;
    cin >> n;

    vector<int> ary(n);
    for (int i = 0; i < n; i++) {
        cin >> ary[i];
    }

    shellSort(ary);
    cout << G.size() << endl;
    for (auto i = G.size()-1; i >= 1; i--) {
        cout << G[i] << " ";
    }
    cout << G[0] << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << ary[i] << endl;
    }

    return 0;
}