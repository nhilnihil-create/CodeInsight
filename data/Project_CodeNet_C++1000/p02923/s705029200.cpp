#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int c = 0, max_c = 0;
    vector<int> H(N);
    for(int i=0; i<N; i++) {
        cin >> H[i];
    }

    for(int i=0; i<N-1; i++) {
        if(H[i] >= H[i+1]) c++;
        else c = 0;
        max_c = max(max_c, c);
    }
    cout << max_c << endl;
}