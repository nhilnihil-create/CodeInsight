#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using ll = long long;
using uint = unsigned int;
using graph = std::vector<std::vector<ll>>;
using wGraph = std::vector<std::vector<std::pair<ll,ll>>>;
#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;
ll MOD7 = 1000000007;
ll MOD9 = 1000000009;
vector<ll> InputVec(ll N){
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    return A;
}
void OutputVec(vector<ll> A){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;
}
vector<vector<ll>> InputVec2d(ll H,ll W){
    vector<vector<ll>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            cin >> A[yi][xi];
        }
    }
    return A;
}
vector<vector<char>> InputVec2dStr(ll H,ll W){
    vector<vector<char>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<char>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        string S;
        cin >> S;
        for (int xi = 0; xi < W; ++xi) {
            A[yi][xi] = S[xi];
        }
    }
    return A;
}

void OutputVec2d(vector<vector<ll>> A){
    for (int yi = 0; yi < A.size(); ++yi) {
        for (int xi = 0; xi < A[yi].size(); ++xi) {
            cout << A[yi][xi] << ",";
        }
        cout << endl;
    }
}

graph InputGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return G;
}
graph InputDGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
    }
    return G;
}

void OutputGraph(graph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j]<< ",";
        }
        cout << endl;
    }
}

void OutputAnswerBool(bool b,bool isUpperCase = false){
    if(b){
        if(isUpperCase){
            cout << "YES" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }else{
        if(isUpperCase){
            cout << "NO" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

int main() {
    string S;
    cin >> S;
    vector<vector<ll>> memo(2);
    for (int i = 0; i < 2; ++i) {
        memo[i] = vector<ll>(S.size());
    }
    for (int i = 0; i < S.size(); ++i) {
        memo[0][i] = 0;
        memo[1][i] = 0;
    }
    memo[0][0] = 1;
    memo[1][0] = 1;
    if(S[0] == S[1]){
        memo[0][1] = 0;
    }else{
        memo[0][1] = 2;
    }
    memo[1][1] = 2;

    for (int i = 2; i < S.size(); ++i) {
        if(S[i] == S[i-1] && S[i-2] == S[i] && S[i - 1] == S[i + 1]){
            memo[0][i] = memo[1][i-2] + 1;
            memo[1][i] = memo[0][i-1] + 1;
        }else if(S[i] == S[i-1]){
            memo[0][i] = memo[1][i-2] + 1;
            memo[1][i] = max(memo[1][i-2],memo[0][i-1]) + 1;
        }else if(S[i-2] == S[i] && S[i - 1] == S[i + 1]){
            memo[0][i] = max(memo[1][i-2],memo[0][i-1]) + 1;
            memo[1][i] = memo[1][i-2] + 1;
        }else{
            memo[0][i] = max(memo[1][i-2],memo[0][i-1]) + 1;
            memo[1][i] = max(memo[1][i-2],memo[0][i-1]) + 1;
        }
    }
    //OutputVec2d(memo);
    cout << max(memo[0][S.size()-1],memo[1][S.size()-2]) << endl;
}
