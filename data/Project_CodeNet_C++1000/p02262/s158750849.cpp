#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
const static int MAX = 1000000;
int cnt;
stack<int> G;

void insertionSort(int A[], int n, int g){
    for (int i = g; i < n; ++i) {
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int n){
    cnt = 0;
    int h = 1;
    while (h <= n){
        G.push(h);
        h = 3*h + 1;
    }
    int m = (int)G.size();
    cout << m << endl;

    for (int i = 0; i < m; i++) {
        cout << G.top() << " ";
        insertionSort(A, n, G.top());
        G.pop();
    }
    cout << endl;

    cout << cnt << endl;
    for (int i = 0; i < n; i++) cout << A[i] << endl;

}

int main() {
    int A[MAX], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    shellSort(A, n);
    return 0;
}
