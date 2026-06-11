#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,max = 0; cin >> N;
    long long sum = 0;

    for(int i = 0; i < N; ++i) {
        int tall; cin >> tall;
        if(max <= tall) max = tall;
        else sum += (max - tall);
    }
    cout << sum << endl;
}