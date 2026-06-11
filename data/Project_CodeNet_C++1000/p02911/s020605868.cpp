#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, Q;
    cin >> N >> K >> Q;
    vector <long long> P(N, K-Q);
    for (long long i=0; i<Q; i++) {
        long long tmp;
        cin >> tmp;
        P.at(tmp-1)++;
    }
    for (long long i=0; i<N; i++) {
        if (P.at(i)>0) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }
}