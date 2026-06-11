#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<double>vec(N);
    for (int i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());
    double num = vec[0];
    for (int i=1; i<N; i++) {
        num = (num + vec[i]) / 2;
    }

    cout << num << endl;
    return 0;
}