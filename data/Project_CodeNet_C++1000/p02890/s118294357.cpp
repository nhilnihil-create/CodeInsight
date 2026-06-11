#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[a]++;
    }
    sort(A.begin(), A.end());
    vector<int> sum(N+1);
    sum[1] = A[1];
    for (int i = 2; i <= N; i++) sum[i] = sum[i-1]+A[i];
    int cnt = 1;
    vector<int> ans(N+1, 0);
    for (int K = N; K >= 1; K--) {
        while(true){
            auto it = lower_bound(A.begin(), A.end(), cnt);
            int t = distance(it, A.end());
            if (t*cnt+sum[N-t] < K*cnt) break;
            else cnt++;
        }
        ans[K] = cnt-1;
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << endl;
    return 0;
}
