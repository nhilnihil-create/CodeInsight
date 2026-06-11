#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long ll;


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) num[i] = i + 1;
    vector<int> P(n);
    vector<int> Q(n);
    for (int i = 0; i < n; i++) cin >> P[i];
    for (int i = 0; i < n; i++) cin >> Q[i];
    int countP, countQ, cnt = 0;
    do {
        cnt++;
        if (P == num) countP = cnt;
        if (Q == num)countQ = cnt;
    } while (next_permutation(num.begin(), num.end()));
    cout << abs(countP - countQ) << endl;
}
