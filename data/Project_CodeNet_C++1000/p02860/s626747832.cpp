#include <bits/stdc++.h>          
using namespace std;
typedef long long ll;

int main() {
    int N;
    string S;
    cin >> N;
    cin >> S;
    string ans = "Yes";
    if (N%2!=0) {
        cout << "No" << endl;
        exit(0);
    }
    vector<char> T(N/2);
    for (int i=0; i<N/2; i++) {
        T[i] = S[i];
    }
    ans = "Yes";
    for (int i=N/2; i<N; i++) {
        if (T[i-N/2]!=S[i]) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}