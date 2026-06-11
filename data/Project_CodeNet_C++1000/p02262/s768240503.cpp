#include <iostream>
#include <vector>
using namespace std;

void intervals(int max, vector<int>& G) {
    int g = 1;
    while (g <= max) {
        G.push_back(g);
        g = 3 * g + 1;
    }
}

int insertionSort(int N, int A[], int g) {
    int n_swapped = 0;
    for (int i = g; i < N; i++) {
        int v = A[i];
        int iBef = i - g;
        while (0 <= iBef && v < A[iBef]) {
            A[iBef + g] = A[iBef];
            iBef -= g;
            n_swapped++;
        }
        A[iBef + g] = v;
    }
    return n_swapped;
}

int shellSort(int N, int A[], vector<int>& G) {
    int n_swapped = 0;
    for (int i = G.size() - 1; i >= 0; i--) {
        n_swapped += insertionSort(N, A, G[i]);
    }
    return n_swapped;
}

/* ALDS1_2_D: Shell Sort */
int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> G;
    intervals(N, G);

    int n_swapped = shellSort(N, A, G);

    cout << G.size() << endl << G.back();
    for (int i = G.size() - 2; i >= 0; i--)
        cout << " " << G[i];
    cout << endl;

    cout << n_swapped << endl;
    for (int i = 0; i < N; i++)
        cout << A[i] << endl;

    return 0;
}