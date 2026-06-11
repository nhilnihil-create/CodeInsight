#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int>vec(N);
    vector<int>hikaku(N);
    for (int i=0; i<N; i++) {
        cin >> vec.at(i);
        hikaku[i] = vec[i];
    }

    sort(hikaku.begin(), hikaku.end(), greater<int>());
    for (int i=0; i<N; i++) {
        int num = hikaku[0];
        if (hikaku[0] == vec[i]) {
            num = hikaku[1];
        }

        cout << num << endl;
    }
    return 0;
}