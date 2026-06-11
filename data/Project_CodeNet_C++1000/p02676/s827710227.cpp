#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    int K;
    cin >> K;
    string S;
    cin >> S;
    int N = S.size();
    vector<char> s(N);
    for (int i=0; i<N; i++) {
        s[i] = S[i];
    }
    if (N<=K) {
        cout << S << endl;
        exit(0);
    }
    else {
        for (int i=0; i<K; i++) {
            cout << s[i];
        }
        cout << "..." << endl;
    }
}