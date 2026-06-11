#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 246913

bool table[MAX_N];
vector<int> prime;

void init() {
    memset(table, 1, sizeof(table));
    table[0] = table[1] = false;
    for (int i = 2; i < MAX_N; i++) {
        if (table[i]) {
            prime.push_back(i);
            for (int j = i + i; j < MAX_N; j += i) {
                table[j] = false;
            }
        }
    }
}

int main() {
    int n;
    init();
    while (cin >> n, n != 0) {
        cout << upper_bound(prime.begin(), prime.end(), n+n) 
                    - upper_bound(prime.begin(), prime.end(), n) << endl;
    }
    return 0;
}