#include <iostream>
#include <deque>

using namespace std;

long long cnt = 0;
deque<int> G;

void insertionSort(int A[], int N, int g) {
    for (int i = g; i < N; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shellSort(int A[], int N) {
    for (int h = 1; ; ) {
        if (h > N) {
            break;
        }
        G.push_front(h);
        h = 3*h + 1;
    }

    for (auto g : G) {
        insertionSort(A, N, g);
    }
}

int main() {
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    shellSort(A, N);

    cout << G.size() << endl;

    for (int i = 0; i < G.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << G[i];
    }
    cout << endl;

    cout << cnt << endl;

    for (auto a: A) {
        cout << a << endl;
    }

    return 0;
}