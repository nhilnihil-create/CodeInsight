#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
    int n, N[10000];
    int q, Q[500];
    int count = 0;

    cin >> n;
    for (int i = 0; i< n; i++) {
        cin >> N[i];
    }

    cin >> q;
    for (int j = 0; j< q; j++) {
        cin >> Q[j];
    }

    for (int j = 0; j < q; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < i; k++) {
                if (N[k] == N[i]) goto SAME;
            }
            if (Q[j] == N[i]) count++;
            SAME:;
        }
    }
    cout << count << endl;
}