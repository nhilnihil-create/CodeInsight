#include <bits/stdc++.h>
using namespace std;
string S;
long long K, C;
vector<int> dp, cnt, can;
bool dfs(int ind, int cnt1){
    if(dp[ind] != 0){
        if(dp[ind] == cnt1) return true;
        return false;
    }
    auto ite = upper_bound(can.begin(), can.end(), can[ind] + C);
    if(ite == can.end()){
        if(cnt1 == K){
            dp[ind] = cnt1;
            cnt[cnt1]++;
            return true;
        }
        return false;
    }
    int ind2 = ite - can.begin();
    bool flag = dfs(ind2, cnt1 + 1);
    if(flag){
        dp[ind] = cnt1;
        cnt[cnt1]++;
        return true;
    }
    return false;
}
int main(){
    long long N;
    cin >> N >> K >> C;
    cin >> S;
    can.resize(0);
    for(int i = 0; i < N; i++){
        if(S[i] == 'o') can.push_back(i + 1);
    }
    int size= can.size();
    dp.resize(size, 0);
    cnt.resize(K + 1, 0);
    dfs(0, 1);
    int flag = 0;
    for(int i = 0; i < size; i++){
        if(dp[i] == K) flag = 1;
        if(dp[i] > K){
            cout << endl;
            return 0;
        }
    }
    if(flag == 0){
        cout << endl;
        return 0;
    }
    for(int i = 0; i < size; i++){
        if(dp[i] != 0) continue;
        int temp;
        if(can[i] - C - 1 < can[0]) temp = 1;
        else{
            int inde = upper_bound(can.begin(), can.end(), can[i] - C - 1) - can.begin() - 1;
            temp = dp[inde] + 1;
        }
        dfs(i, temp);
    }
    for(int i = 0; i < size; i++){
        if(cnt[dp[i]] == 1) cout << can[i] << endl;
    }
}