#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using ull = unsigned long long;
using ll = long long;
using namespace std;

int main(void) {
    int K, N;
    cin >> K >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // vector<int> AS(N+2);
    vector<int> AS;
    int as = 0;
    AS.push_back(as);
    int last = 0;
    for (int i = 0; i < N; ++i) {
        as += A[i] - last;
        AS.push_back(as);
        last = A[i];
    }
    AS.push_back(as+K-A[A.size()-1]);

    // for (const auto& i : AS) {
    //     cout << i << " ";
    // }
    // cout << endl;

    int ans = 1e8;
    for (int sp = 1; sp < N+1; sp++) {
        int tmp;
        if (sp == 1) {
            tmp = AS[N] - AS[1];
        } else {
            tmp = AS[N+1] - AS[sp] + AS[sp-1];
        }
        // printf("tmp: %d\n", tmp);
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}