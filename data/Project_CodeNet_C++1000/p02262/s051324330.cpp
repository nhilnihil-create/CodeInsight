/*
ALDS1_2_D
*/

#include <iostream>
#include <vector>

using namespace std;

static const int MAX = 1000000;

int cnt;

void insertionSort(int A[], int n, int g) {
    for(int i = g; i < n; i++) {
        int v = A[i];
        int j = i-g;
        while( (j >= 0) && (A[j] > v) ) {
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int n) {
    cnt = 0;

    vector<int> G;

    for(int i = 1; i <= n; ) {
        G.push_back(i);
        i = 3*i + 1;
    }


    for(int i = G.size()-1; i >= 0; i--) {
        insertionSort(A, n, G[i]);
    }

    cout << G.size() << endl;
    for(int i = G.size()-1; i >= 0; i--) {
        cout << G[i];
        if(i) cout << " ";
    }
    cout << endl << cnt << endl;
}

int main() {
    int n;
    int A[MAX];

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    shellSort(A, n);

    for(int i = 0; i < n; i++) {
        cout << A[i] << endl;
    } 

}
