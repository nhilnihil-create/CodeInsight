#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t N;
    cin >> N;
    vector<int64_t>vec(N);
    for (int64_t i = 0; i< N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());
    int64_t size = vec.size();
    int64_t kazu = vec[size/2] - vec[size/2-1];
    cout << kazu << endl;
    return 0;
}