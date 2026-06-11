#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out, n) for(int i=0; i<n; i++) cout<<out[i]<<endl

int main(){
    int N, M, X;
cin >> N >> M >> X;
int C[N], A[N][M];
for (int i = 0; i < N; i++) {
    cin >> C[i];
    for (int j = 0; j < M; j++) {
        cin >> A[i][j];
    }
}

int ans = INT32_MAX;
for (int i = 1; i < (1<<N); i++) {
    int a[M]{};
    int v = 0;
    for (int j = 0; j < N; j++) {
        if (i & (1<<j)) {
            v += C[j];
            for (int k = 0; k < M; k++) {
                a[k] += A[j][k];
            }
        }
    }
    for (int j = 0; j < M; j++) {
       if (a[j] < X) break;
       if (j == M - 1) {
           ans = min(ans, v);
       }
    }
}
if (ans != INT32_MAX) {
    cout << ans << "\n";
} else {
    cout << "-1\n";
}
}
