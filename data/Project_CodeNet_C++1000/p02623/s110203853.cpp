#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi   = vector<int>;
using vll  = vector<ll>;
using vc   = vector<char>;
using vvll  = vector<vll>;
using vvi  = vector<vi>;
using vvc  = vector<vc>;
using vb   = vector<bool>;
using vvb  = vector<vb>;
using pii  = pair<int,int>;
using vpii = vector<pii>;


int main() {
    int N, M, K; cin >> N >> M >> K;
    vll A(N); for(int i = 0; i < N; i++) cin >> A.at(i);
    vll B(M); for(int i = 0; i < M; i++) cin >> B.at(i);

    vll A_time(N+1), B_time(M+1);
    int max_i=0,tmp_j=M;int ans = 0;
    for(int i = 0; i < N; i++){
        A_time.at(i+1) = A_time.at(i)+A.at(i);
        if (A_time.at(i+1) < K) max_i = i+1;
    }
    for(int j = 0; j < M; j++){
        B_time.at(j+1) = B_time.at(j)+B.at(j);
    }
    for (int i = 0; i <= N; i++) {
        if(A_time.at(i) > K) break;
        while(B_time.at(tmp_j)>K-A_time.at(i)) {
            tmp_j--;
        }
        ans = max(ans, i+tmp_j);
    }

    cout << ans << endl;
}