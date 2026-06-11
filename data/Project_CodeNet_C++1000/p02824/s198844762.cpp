#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N, V, P;  ll M; cin >> N >> M >> V >> P;
    ll A[N]; rep(i, N) cin >> A[i];
    sort(A, A+N);
    int ng = -1, ok = N;
    int m = (ng+ok)/2;
    while(abs(ng-ok) > 1){
        //問題mは採用される可能性があるか?
        //問題mがそもそも上からp番目以内ならok
        if(N-m <= P) ok = m;
        else if(A[m] + M < A[N-P]) ng = m; //P番目をジャッジが選ばなくてもm番目の問題が越せない場合は無理
        else{
            int rem = V - (P+m); //必ず選ぶものは上からP-1番目までと下からm番目まで
            if(rem <= 0) ok = m;
            else{
                //A[m]より大きいスコアの問題をrem問選ぶことをM回繰り返す
                //A[m+1], ..., A[N-P]のそれぞれに,A[m] + Mを超えないようになるべく多くスコアを分配した結果,
                //分配した数の合計がrem*M以上ならok 未満ならng
                //各問題に振れるスコアの上限値はM
                //というか、Mより大きい値を振ったら絶対A[m] + Mを超える(Aは昇順なので)
                ll acc = 0;
                for(int i = m+1; i <= N-P; i++){
                    acc += (A[m] + M) - A[i];
                }
                if(acc >= M*rem) ok = m;
                else ng = m;
            }
        }
        m = (ng+ok)/2;
    }
    cout << N-ok << endl;
    return 0;
}