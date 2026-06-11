#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t
ll ans = -1;

pair<string, ll> dfs(string S, ll cnt){
    if(S.size() == 1){
        return {S, cnt};
    }
    int n1 = S[0]-48;
    int n2 = S[1]-48;

    if(n1+n2 >= 10){
        S[0] = (n1+n2)/10+48;
        S[1] = (n1+n2)%10+48;
        return dfs(S, cnt+1);
    }
    else{
        S[0] = (n1+n2)+48;
        S.erase(S.begin()+1);
        return dfs(S, cnt+1);
    }
    //return res;
}



int main(){
    //テーブルを二つ、０は９と同じ
    ll M; cin >> M;
    vector<vector<pair<string, ll>>> T1(11, vector<pair<string, ll>>(11)); //何になるかと何回変換するか
    for(int i = 1; i <= 9; i++){
        string S; 
        for(int j = 0; j <= 9; j++){
            if(j == 0){
                T1[i][0] = {"", 0};
                continue;
            }
            S += i+48;
            auto p = dfs(S, 0);
            T1[i][j] = dfs(S, 0);
        }
    }
    vector<pair<string, ll>> T2(101);
    for(int i = 0; i < 100; i++){
        string S = to_string(i);
        T2[i] = dfs(S, 0);
    }

    vector<ll> D(M), C(M);

    for(int i = 0; i < M; i++){
        cin >> D[i] >> C[i];
    }
    vector<string> V(M);
    ll ans = 0;

    for(int i = 0; i < M; i++){
        ll d = D[i], c = C[i];
        if(d == 0){
            V[i] = "0";
            ans += c-1;
            continue;
        }
        ll ds = 0;
        ds += (c/9)*(d+9);
        pair<string, ll> p = T1[d][c%9];
        if(c%9 == 0) {
            p.first = T1[d][9].first;
            ds -= (d+9);
            ds += T1[d][9].second;
        }
        ds += p.second;
        ans += ds;
        V[i] = p.first;
    } 


    string T = V[0];
    for(int i = 1; i < M; i++){
        string U = T; U += V[i];
        auto p = T2[stoll(U)];
        T = p.first;
        ans += p.second;

    }
    cout << ans << endl;
}