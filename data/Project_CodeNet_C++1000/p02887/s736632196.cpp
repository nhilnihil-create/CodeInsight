#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int count = 1;
    rep(i, N-1) {
        if (S[i] == S[i+1])
            continue;
        count++;
    }
    cout << count << endl;
}