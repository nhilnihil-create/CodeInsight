#include <iostream>
#include <vector>

using namespace std;

long long g_count = 0;
const int MAX_N = 1000000;
vector<int> g;

void insertionSort(int *a, int n, int g) {
    for (int i = g; i < n; i++) {
        int v = a[i];
        int j = i - g;
        while (j >= 0 && a[j] > v) {
            a[j+g] = a[j];
            j = j - g;
            g_count++;
        }
        a[j + g] = v;
    }
}

int shellSort(int *a, int n) {

    for (int i = 1; ;) {
        if (i > n) {
            break;
        }
        g.push_back(i);
        i = 3 * i + 1;
    }

    for (int i = g.size() - 1; i >= 0; i--) {
        insertionSort(a, n, g[i]);
    }
    return g_count;
}

int main() {
    int n;
    int a[MAX_N];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = shellSort(a, n);
    
    cout << g.size() << endl;
    for (int i = g.size() - 1; i >= 0; i--) {
        cout << g[i] << " ";
    }
    cout << endl;
    cout << count << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}