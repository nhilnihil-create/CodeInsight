#include <iostream>
using namespace std;

static const int NMAX = 1000000;
static const int MMAX = 100;
static const int AMAX = 1e9;


void insertionSort(const int N, int A[], int g, int* cnt)
{
    for (int i=g; i < N; i++) {
        int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j = j - g;
            *cnt += 1;
        }
        A[j+g] = v;
    }
}

void shellSort(int N, int A[]) {
    int cnt = 0;
    int m = 0;
    int g = 1;
    int G[MMAX];
    
    while (1) {
        G[m] = g;
        m++;
        g = 3*g + 1;
        if ( g > N) break;
    }

    for (int i = m; i > 0; i--) {
        insertionSort(N, A, G[i-1], &cnt);
    }

    cout << m << endl;
    for (int i = m; i > 1; i--) {
        cout << G[i-1] << " ";
    }
    cout << G[0] << endl;
    cout << cnt << endl;
    for (int i = 0; i < N; i++) {
        cout << A[i] << endl;
    }
}

int main (void) {

    int N;
    int* A;

    cin >> N;
    A = new int[N];
    for (int i=0; i < N; i++) cin >> A[i];
    
    shellSort(N, A);
}

