#include <bits/stdc++.h>

#include <vector>

using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    int N = S.length() + 1;
    vector<int> a(N, -1);
    for (int i = 0; i < N; i++) {
        if (i == 0 && S[0] == '<') {
            a[0] = 0;
            int j = i + 1;
            while (j < N) {
                if (S[j - 1] == '<') {
                    a[j] = max(a[j - 1] + 1, a[j]);
                }
                if (S[j - 1] == '>') break;
                j++;
            }
        } else if (i == N - 1 && S[N - 2] == '>') {
            a[N - 1] = 0;
            int j = i;
            while (j >= 0) {
                if (S[j] == '>') {
                    a[j] = max(a[j + 1] + 1, a[j]);
                }
                if (S[j] == '<') break;
                j--;
            }
        }
        if (S[i] == '>' && S[i + 1] == '<') {
            a[i + 1] = 0;
            int j = i;
            while (j >= 0) {
                // if (a[j] != -1) break;
                if (S[j] == '>') {
                    a[j] = max(a[j + 1] + 1, a[j]);
                }
                if (S[j] == '<') break;
                j--;
            }
            j = i + 2;
            while (j < N) {
                // if (a[j] != -1) break;
                if (S[j - 1] == '<') {
                    a[j] = max(a[j - 1] + 1, a[j]);
                }
                if (S[j - 1] == '>') break;
                j++;
            }
        }
    }

    // cout << a[0];
    ll output = a[0];
    for (int i = 1; i < N; i++) {
        output += a[i];
        // cout << " " << S[i - 1] << " " << a[i];
    }
    // cout << endl;
    cout << output << endl;

    return 0;
}
