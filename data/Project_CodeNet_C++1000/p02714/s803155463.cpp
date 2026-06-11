#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    long long r = 0, g = 0, b = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'R') r++;
        else if (S[i] == 'G') g++;
        else b++;
    }
    long long minus = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            if (S[i] == S[j]) continue;
            int k = j * 2 - i;
            if (k >= N || S[i] == S[k] || S[j] == S[k]) continue;
            minus++;
        }
    }
    cout << r * g * b - minus << endl;
    return 0;
}