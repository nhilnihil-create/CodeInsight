#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

long long f(string s) {
    int N = s.size();
    long long sum = 0;
    for (long long i = 0, j = 0; i < N; i = j) {
        while (j < N && s[i] == s[j])j++;
        sum += (j - i) / 2;
    }
    return sum;
}

int main() {

    string S;
    cin >> S;

    long long N = S.size();

    long long K;
    cin >> K;

    bool same = true;
    for (int i = 0; i < N; i++) if (S[0] != S[i]) same = false;
    if (same) {
        cout << (N * K) / 2 << endl;
        return 0;
    }

    long long d1 = f(S);
    long long d2 = f(S + S);

    long long a = d1;
    long long d = d2 - d1;

    cout << a + (K -1) * d << endl;

    return 0;
}

