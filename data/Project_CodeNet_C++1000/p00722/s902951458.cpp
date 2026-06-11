#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_T 1000001

bool table[MAX_T];
vector<int> prime;

void init() {
    memset(table, 1, sizeof(table));
    table[0] = table[1] = false;
    for (int i = 2; i < MAX_T; i++) {
        if (table[i]) {
            prime.push_back(i);
            for (int j = i + i; j < MAX_T; j+=i) {
                table[j] = false;
            }
        }
    }
}

int main() {
    int a, d, n;
    init();
    while (cin >> a >> d >> n) {
        if (a == 0 && d == 0 && n == 0) break;
        int p = 0;
        for (int i = 0; ; i++) {
            if (table[a + d*i]) {
                p++;
            }
            if (p == n) {
                cout << a + d*i << endl;
                break;
            }
        }
    }
    return 0;
}