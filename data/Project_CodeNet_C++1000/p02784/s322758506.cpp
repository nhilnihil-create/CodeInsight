#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define cn cout << '\n'
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ii pair < int, int >
#define iii pair < int, ii >
#define INF 987654321
#define LINF 987654321987654321

string bin(int H, int A[], int n) {
    for (int i = 0; i < n; ++i) {
        H -= A[i];
        if (H <= 0) return "Yes";
    }
    return "No";
}

int main() {
    cio;
    int H, N;
    cin >> H >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    cout << bin(H, A, N);
    cn;
}
