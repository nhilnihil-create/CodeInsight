#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

int main(void) {
    while (true) {
        int n;
        int r;
        cin >> n >> r;
        if (n == 0) {
            break;
        }

        VI hana(n);
        for (int i = 0; i < n; i++) {
            hana[i] = n - i;
        }
        for (int i = 0; i < r; i++) {
            int p;
            int c;
            cin >> p >> c;
            VI temp(p - 1);
            for (int j = 0; j < p - 1; j++) {
                temp[j] = hana[j]; 
            }
            for (int j = 0; j < c; j++) {
                hana[j] = hana[j + p - 1]; 
            }
            for (int j = 0; j < p - 1; j++) {
                hana[j + c] = temp[j]; 
            }
        }
        cout << hana[0] << endl;
    }
    return 0;
}