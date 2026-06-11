#include <bits/stdc++.h>


using namespace std;


void z_algorithm(string &S, vector<int>& z) {
    z.resize(S.length());
    z[0] = S.length();
    int i = 1, j = 0;
    while (i < S.length()) {
        while (i + j < S.length() && S[j] == S[i + j])
            j++;
        z[i] = j;
        if (j == 0) {
            i++;
            continue;
        }

        int k = 1;
        while (k < j && k + z[k] < j) {
            z[i + k] = z[k];
            k++;
        }
        i += k;
        j -= k;
    }
}


int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<vector<int>> Z(N);
    for (int i = 0; i < N; i++) {
        string ss = S.substr(i);
        z_algorithm(ss, Z[i]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Z[i].size(); j++) {
            if (j >= Z[i][j]) {
                ans = max(ans, Z[i][j]);
            }
        }
    }
    cout << ans << endl;
}
