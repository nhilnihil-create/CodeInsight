#include <iostream>
#include <cstdio>

const int MAX = 1000000;

using namespace std;

int count_exchange = 0;
int count_g = 0;

int each_g[500000];

void insertion(int a[], int n, int g) {
    for (int i = g; i < n; ++i) {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j+g] = a[j];
            j -= g;
            ++count_exchange;
        }
        a[j+g] = v;
    }
}

void shell_sort(int a[], int n) {
    int g = n;
    do {
        g = g / 3 + 1; 
        each_g[count_g++] = g;
        insertion(a, n, g);
    } while (g > 1);
}

void print(int a[], int n) {
    for (int i = 0; i < n; ++i)
        cout << a[i] << endl;
}

int
main(int argc, const char *argv[])
{
    int N;
    int a[MAX];
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    shell_sort(a, N);
    cout << count_g << endl;
    for (int i = 0; i < count_g; ++i) {
        if (i) cout << " ";
        cout << each_g[i];
    }
    cout << endl << count_exchange << endl;
    print(a, N);

    return 0;
}