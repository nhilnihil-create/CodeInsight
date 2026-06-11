#include <iostream>
#include <cmath>
using namespace std;

static int swap_count = 0;
void insert_sort(int* a, int length, int interval);
void shell_sort(int* a, int length);
void print(int* a, int length) {
    for (int i = 0; i < length; ++i) {
        cout << a[i] << endl;
    }
}


int main() {
    int length = 0;
    cin >> length;
    int* a = new int[length];
    for (int i = 0; i < length; ++i) {
        cin >> a[i];
    }

    shell_sort(a, length);
    return 0;
}

void insert_sort(int* a, int length, int interval) {
    for (int i = interval; i < length; ++i) {
        int v = a[i];
        int j = i - interval;
        while (j >= 0 && a[j] > v) {
            a[j + interval] = a[j];
            j -= interval;
            ++swap_count;
        }
        a[j + interval] = v;
    }
}
void shell_sort(int* a, int length) {
    swap_count = 0;
    int m = max(1, (int) floor(log(length) / log(2)));
    int* intervals = new int[m];
    cout << m << endl;
    int length_copy = length;
    bool is_first = true;
    for (int i = 0; i < m; ++i) {
        intervals[i] = length_copy / 2;
        if (is_first) {
            is_first = false;
        } else {
             cout << " ";
        }
        cout << intervals[i];
        length_copy /= 2;
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        insert_sort(a, length, intervals[i]);
    }
    cout << swap_count << endl;
    print(a, length);
}