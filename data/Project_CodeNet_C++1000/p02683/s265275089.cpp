#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;
typedef pair<int, int> PII;

vector<int> Addition(vector<int> A, vector<int> B, int N){
    vector<int> temp(N);
    for(int i = 0 ; i < N ; i++){
        temp[i] = A[i] + B[i];
    }
    return temp;
}

int main() {
    int n, m, x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> A(n, vector<int>(m));
    rep(i, n) {
        cin >> c.at(i);
        rep(j, m) {
            cin >> A.at(i).at(j);
        }
    }
    int ans = 10000000;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<int> temp(m, 0);
        int cost = 0;
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(bit >> j & 1){
                temp = Addition(A.at(j), temp, m);
                cost += c.at(j);
            }
        }
        for(auto v : temp) if(v < x) flag = false;
        if(flag) ans = min(ans, cost);
    }
    cout << (ans == 10000000 ? -1 : ans) << endl;

    return 0;
}