#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector <long long> A(N);
    long long b=0;
    long long b2=0;
    for (long long i=0; i<N; i++) {
        cin >> A.at(i);
        if (A.at(i)>=b) {
            b2 = b;
            b = A.at(i);
        }
        else {
            b2 = max(b2,A.at(i));
        }
    }
    for (long long i=0; i<N; i++) {
        if (A.at(i)==b) cout << b2 << endl;
        else cout << b << endl;
    }
}