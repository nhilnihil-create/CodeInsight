#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(M);
    vector<char> C(M);

    for(int i=0; i<M; i++) {
        cin >> S[i] >> C[i];
    }

    for(int i=0; i<1000; i++) {
        bool flg = true;
        string num_s = to_string(i);
        for(int j=0; j<M; j++) {
            if(num_s[S[j]-1] != C[j] || num_s.size() != N){
                flg = false;
            }
        }
        if(flg && num_s.size() == N) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}