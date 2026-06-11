#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, M;
    cin >> N >> M;

    vector<int> A(N), W(N);

    for(int i=0; i<M; i++) {
        int a;
        string s;
        cin >> a >> s;

        if(s == "WA" && A[a-1] != 1) {
            W[a-1]++;
        }
        else if(s == "AC") {
            A[a-1] = 1;
        }
    }
    int a_sum = 0, w_sum = 0;
    for(int i=0; i<N; i++) {
        a_sum += A[i];
        if(A[i] == 1) {
            w_sum += W[i];
        }
    }
    cout << a_sum << " " << w_sum << endl;
}

