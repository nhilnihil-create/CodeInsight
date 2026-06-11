#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    long long K;
    cin >> N >> M >> K;

    long long A[N], B[M];
    long long Asum[N], Bsum[M];

    for(int i=0; i<N; i++){
        cin >> A[i];
        if(i==0){
            Asum[i] = A[i];
        }else{
            Asum[i] = Asum[i-1] + A[i];
        }
    }

    for(int i=0; i<M; i++){
        cin >> B[i];
        if(i==0){
            Bsum[i] = B[i];
        }else{
            Bsum[i] = Bsum[i-1] + B[i];
        }
    }

    int ans = 0;
    int tmp;

    auto it = upper_bound(Bsum, Bsum+M, K);
    int j = it - Bsum - 1;

    ans = max(j+1, ans);    

    for(int i=0; i<N; i++){
        if( Asum[i] > K ) continue;

        long long Kb = K - Asum[i];
        it = upper_bound(Bsum, Bsum+M, Kb);
        j = it - Bsum - 1;
        if( j<0 ){
            tmp = i + 1;
        }else{
            tmp = i + j + 2;
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}