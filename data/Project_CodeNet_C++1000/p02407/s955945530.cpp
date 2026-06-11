#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[110];
    for (int i = 0; i < N; i++)cin >> a[i];
    reverse(a, a + N);
    for (int i = 0; i < N; i++) {
        if (i == N - 1)cout << a[i] << endl;
        else cout << a[i] << ' ';
    }
}
