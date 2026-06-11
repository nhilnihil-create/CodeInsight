#include <bits/stdc++.h>
using namespace std;

int main(){
    int K, Q;
    cin >> K >> Q;
    vector<int> D(K);
    for(int i=0; i<K; i++) scanf("%d", &D[i]);

    while(Q--){
        int N, X, M;
        scanf("%d %d %d", &N, &X, &M);
        N--;
        X %= M;

        int L = N/K, R = N%K;

        int64_t sum = X;
        for(int i=0; i<K; i++){
            int64_t d = D[i] % M;
            if(d == 0) d = M;
            sum += (i<R ? L+1 : L)*d;
        }
        int ans = N-sum/M;
        printf("%d\n", ans);
    }
    return 0;
}
