#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
ll N,K;
cin >> N >> K;
rep(i,INF) {
    if (N < pow(K,i)) {
        cout << i << endl;
        return 0;
    }
}



return 0;
}
