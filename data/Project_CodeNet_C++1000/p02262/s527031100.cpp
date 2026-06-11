
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>

using namespace std;

void print_func(int *array, int size){
    for (int j = 0; j < size; ++j) {
        cout << ( j ? " " : "" ) << array[j];
    }
    cout << endl;
}

int insertionSort(int *A, int n, int g) {
    int v, cnt=0;
    for (int i = g; i < n; i++) {
        v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j + g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j + g] = v;
    }

    return cnt;
}

int get_m(int n){
    int h = 1;
    int res = 0;
    while (h <= n){
        h = 3 * h + 1;
        res++;
    }

    return res;
}

void shellSort(int *A, int n) {
    int m = min(get_m(n), 100);

    int G[m];
    int h = 1;
    for (int i = m - 1; i >= 0 ; i--) {
        G[i] = h;
        h = 3*h + 1;
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += insertionSort(A, n, G[i]);
    }

    cout << m << endl;
    print_func(G, m);
    cout << cnt << endl;

    for (int i = 0; i < n; ++i) {
        cout << A[i] << endl;
    }

}

int main(){
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    shellSort(A, N);

}