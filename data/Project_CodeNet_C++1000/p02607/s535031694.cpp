#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < N; i+=2) {
        if((v[i] % 2 != 0)) {
            count++;
        }
    }
    cout << count;
    return 0;
}