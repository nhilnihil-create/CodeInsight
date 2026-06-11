#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> H(N);
    for (long long i=0; i<N; i++) cin >> H.at(i);
    long long m = H.at(N-1);
    for (long long i=N-1; i>=0; i--) {
        if (H.at(i)-1 > m) {
            cout << "No\n";
            return 0;
        }
        m = min(m, H.at(i));
    }
    cout << "Yes\n";
}