#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Z_algo(string &S, vector<int> &v) {
    int N = S.size();
    v = vector<int>(N, 0);
    v[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i+j < N && S[j] == S[i+j]) {
            j++;
        }
        v[i] = j;
        int k = 1;
        while (i+k < N && k+v[k] < v[i]) {
            v[i+k] = v[k];
            k++;
        }
        i += k;
        j = max(j-k, 0);
    }
    
    return;
}


int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    vector<int> table(N, 0);
    for (int i = 0; i < N; i++) {
        string T = S.substr(i, N-i);
        Z_algo(T, table);
        for (int j = 1; j < N-i; j++) {
            ans = max(ans, min(table[j], j));
        }
    }
    cout << ans << endl;
    return 0;
}