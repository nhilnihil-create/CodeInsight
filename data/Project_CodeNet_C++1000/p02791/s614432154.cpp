#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i=0; i<N; i++) cin >> P[i];

    int min_value = P[0];
    int count = 0;
    for(int i=0; i<N; i++) {
        min_value = min(P[i], min_value);
        if(P[i] <= min_value) {
            count++;
        }
    }
    cout << count << endl;
}

