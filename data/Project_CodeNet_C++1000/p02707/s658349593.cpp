#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> V(N+1);
    for(int i=2; i<=N; i++) {
        int n;
        cin >> n;
        V[n]++;
    }

    for(int i=1; i< V.size(); i++) {
        cout << V[i] << endl;
    }
}