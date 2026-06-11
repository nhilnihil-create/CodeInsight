#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int N,M,Q;
ll ans = 0;
int a[60],b[60],c[60],d[60];

void dfs(vector<int> &A) {
    // 数列の長さが N に達したら打ち切り
    if ((int)A.size() == N) {

        // 処理
        ll d_sum=0;
        for (int i = 0; i < Q; i++) {
            if(A[b[i]-1]-A[a[i]-1] == c[i]) {
                d_sum += d[i];
            }
        }
        if(ans < d_sum) ans = d_sum;
        return ;
    }

    int prev_last = (A.empty() ? 1 : A.back());
    for (int v = prev_last; v <= M; ++v) {
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}

int main(void) { 
    vector<int> A;
    cin >> N >> M >> Q;
    for(int i=0; i<Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    if(Q==1) {
        cout << d[0] << endl;
        return 0;
    }
    dfs(A);
    cout << ans << endl;
}