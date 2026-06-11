#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;
#define INF 100000000
#define NUM 123456

typedef long long ll;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool prime[2*NUM+1];

void hurui(void) {
    for (int i = 0; i <= 2*NUM; i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= NUM*2; i++) {
        if (prime[i]) {
            for (int j = 2; i * j <= NUM*2; j++) {
                prime[i*j] = false;
            }
        }
    }
}

int main(void) {
    hurui();
    int n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        int cnt = 0;
        for (int i = n+1; i <= 2*n; i++) {
            if (prime[i]) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}