#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<ll> H(N);
    vector<vector<ll>> dp_cost(N+1, vector<ll>(N+1));
    for(int i=0;i<N;i++){
        cin >> H.at(i);
    }
    if(K==N){
        cout << 0;
        return 0;
    }
    for(int i=0;i<N;i++){
        dp_cost.at(1).at(i) = H.at(i);
    }
    for(int i=2;i<=N;i++){
        for(int j=i-1;j<N;j++){
            // 生き残っている数が1少ないところにjが加わる．i:生存数
            if(j==i-1){
                // すべて生き残っている
                if(j==0){
                    dp_cost.at(i).at(j) = H.at(j);
                }else{
                    dp_cost.at(i).at(j) = H.at(0);
                    for(int k=0;k<j;k++){
                        dp_cost.at(i).at(j) += max(0ll, H.at(k+1) - H.at(k));
                    }
                }
            }else{
                // 生き残っていないものもある．生存数が1小さいときと比べて自分が増えている
                ll min_v = dp_cost.at(i-1).at(i-1) + max(0ll, H.at(j) - H.at(i-1));
                for(int k=i-2;k<j;k++){
                    min_v = min(min_v, dp_cost.at(i-1).at(k) + max(0ll, H.at(j) - H.at(k)));
                }
                dp_cost.at(i).at(j) = min_v;
            }
        }
    }
    ll min_v = dp_cost.at(N-K).at(max(0, N-K-1));
    for(int i=max(0, N-K-1);i<N;i++){
        min_v = min(min_v, dp_cost.at(N-K).at(i));
    }
    // for(int i=0;i<5;i++){
    //     cout << "i=" << i;
    //     for(int j=0;j<5;j++){
    //         cout << dp_cost.at(i).at(j) << ", ";
    //     }
    //     cout << endl;
    // }
    
    cout << min_v;
    return 0;
}