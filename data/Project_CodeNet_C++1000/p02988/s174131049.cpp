#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    int ans = 0;
    for(int m = 1; m < N - 1; m++){
        vector<int> three(3);
        three[0] = P[m - 1];
        three[1] = P[m];
        three[2] = P[m + 1];
        sort(all(three));
        if(three[1] == P[m]) ans++;
    }
    cout << ans << endl;
}
