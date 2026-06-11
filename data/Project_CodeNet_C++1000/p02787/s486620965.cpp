#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int H,N;
    cin >> H >> N;  //モンスターの体力H, 魔法の種類N


    vector<int> atk;
    vector<int> cost;

    int atk_max=0;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        if(atk_max<a){
            atk_max=a;
        }
        atk.push_back(a);
        cost.push_back(b);
    }

    vector<int> dp(H+atk_max+1, INF);
    dp[0] = 0;
    for(int i=1; i<H+atk_max+1; i++){
        for(int j=0; j<N; j++){
            if(i-atk[j]>=0){
                dp[i] = min(dp[i], dp[i-atk[j]]+cost[j]);
            }else{
                dp[i] = min(dp[i], cost[j]);
            }
        }
    }
    int ans = 1e9;
    /*
    for(int i=0; i< H + atk_max + 1; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    */
    for(int i = H; i < H + atk_max + 1; i++){
        ans = min(ans,dp[i]);
    }

    cout << ans << endl;
    return 0;
}

