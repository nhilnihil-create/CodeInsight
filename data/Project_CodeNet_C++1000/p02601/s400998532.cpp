#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    long long A, B, C;
    cin >> A >> B >> C;
    int K;
    cin >> K;

    int cnt = 0;

    while (B <= A) {
        B <<= 1;
        ++cnt;
    }

    while (C <= B) {
        C <<= 1;
        ++cnt;
    }

    if (cnt <= K) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


    return 0;
}