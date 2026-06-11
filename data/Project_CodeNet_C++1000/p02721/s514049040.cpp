#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <tuple>
#include <cassert>
#include <memory>
using namespace std;
typedef long long ll;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

int N,K,C;
string S;

int L[200010];
int R[200010];

int main ()
{
    cin >> N >> K >> C >> S;

    int pre = 0;
    int tmp = -1e9;
    for (int i = 1; i <= K; i++) {
        while (S[pre] == 'x' || abs(tmp - pre) <= C) pre++;
        L[i] = pre;
        tmp = pre;
        pre++;
    }

    pre = N - 1;
    tmp = 1e9;
    for (int i = K; i >= 1; i--) {
        while (S[pre] == 'x' || abs(tmp - pre) <= C) pre--;
        R[i] = pre;
        tmp = pre;
        pre--;
    }

    for (int i = 1; i <= K; i++) {
        cerr << L[i]<< " ";
    }
    cerr << endl;
    for (int i = 1; i <= K; i++) {
        cerr << R[i] << " ";
    }
    cerr << endl;

    for (int i = 1; i <= K; i++) {
        if (L[i] == R[i]) {
            cout << L[i] + 1 << endl;
        }
    }

//    cout << cnt << endl;

    return 0;
}
