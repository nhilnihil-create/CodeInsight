#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i=0; i<N; i++) {
        cin >> X[i];
    }
    vector<int> P(100,0);
    for (int i=0; i<100; i++) {
        for (int j=0; j<N; j++) {
            P[i] += (X[j]-(i+1))*(X[j]-(i+1));
        }
    }
    sort(P.begin(),P.end());
    cout << P[0] << endl;
}