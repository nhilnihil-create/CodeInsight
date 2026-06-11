#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
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
wGraph InputWGraph(ll N,ll M){
    wGraph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    return G;
}
wGraph InputDWGraph(ll N, ll M){
    wGraph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        G[a].push_back(make_pair(b,c));
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

void OutputGraph(wGraph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j].first <<"/" << G[i][j].second << ",";
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



struct RMQ {
    ll N;
    const ll MAX = (1ll << 31) - 1ll;
    vector<ll> dat;
    void init(ll n){
        ll tmp = 1;
        while(tmp < n){
            tmp *= 2;
        }
        N = tmp;
        dat = vector<ll>(4 * n);
        for (int i = 0; i < dat.size(); ++i) {
            dat[i] = MAX;
        }
    }
    void update(int i,ll x){
        i += N - 1;
        dat[i] = x;
        while(i > 0){
            i = (i-1)/2;
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
        //OutputVec(dat);
    }
    //[a,b)の最小値を求める
    ll query(ll a, ll b){
        return sub_query(a,b,0,0,N);
    }
    ll sub_query(ll a,ll b,ll k,ll l,ll r){
        if (r <= a || b <= l) { // 範囲外なら考えない
            return MAX;
        } else if (a <= l && r <= b) { // 範囲内なので自身の値を返す
            return dat[k];
        } else {
            ll vl = sub_query(a, b, k * 2 + 1, l, (l + r) / 2);
            ll vr = sub_query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vr,vl);
        }
    }
};


int main() {
    ll N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    auto rmq = new RMQ();
    vector<ll> res(N + 1,-1);
    rmq->init(N+1);
    rmq->update(N,0);
    res[N] = 0;
    //cout << "0,";
    for (int i = N-1; i >= 0; --i) {
        if(S[i] == '1'){
            rmq->update(i,1ll << 50);
            //cout << "inf,";
            continue;
        }
        ll mroute = rmq->query(i+1,min(N+2,i+1+M));
        //cout << mroute + 1 << ",";
        res[i] = mroute + 1;
        rmq->update(i, mroute + 1);
    }
    //OutputVec(res);
    if(res[0] > N){
        cout << -1 << endl;
        return 0;
    }
    ll current = res[0];
    ll previndex = 0;
    for (int i = 0; i <= N; ++i) {
        if(res[i] == -1){
            continue;
        }
        if(res[i] != current){
            current = res[i];
            cout << i - previndex << " ";
            previndex = i;
        }
    }

}
