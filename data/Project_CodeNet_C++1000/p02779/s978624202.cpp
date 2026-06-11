#include <bits/stdc++.h>
using namespace std;

// C - Distinct or Not
int main() {
    int N;
    map<long long, bool> mapA;
    cin >> N;
    long long a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        mapA[a] = true;
    }

    if (N == mapA.size()) cout << "YES";
    else cout << "NO";
}
