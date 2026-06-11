#include <iostream>
using namespace std;

void swap(int &i, int &j) {
    if (i == j) {
    } else if (i < j) {
    } else {
        int tmp;
        tmp = i;
        i = j;
        j = tmp;
    }
}

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    int a, b, c;
    swap(i, j);
    swap(i, k);
    swap(j, k);
    cout << i << " " << j << " " << k << endl;
    return 0;
}