#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

template<class T> inline bool chmin(T& a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class TYPE>
struct edge{
    TYPE to,cost; 
    edge(TYPE t,TYPE c){
        to = t;
        cost = c;
    }
};

int main(){
    int N,Q;
    cin >> N >> Q;
    ll score[N+1];
    ll ans[N+1];
    bool check[N+1];
    vector<vector<int>> child(N+1);
    for(int i = 0; i <= N; i++){
        score[i] = 0;
        ans[i]  = 0;
        check[i] = false;
    }
    for(int i = 0; i < N - 1; i++){
        int a,b;
        cin >> a >> b;
        child[a].emplace_back(b);
        child[b].emplace_back(a);
    }
    for(int i = 0; i < Q; i++){
        int p;
        ll x;
        cin >> p >> x;
        score[p] += x;
    }
    queue<pair<int,int>> que;
    que.push({0,1});
    while(!que.empty()){
        pair<int,int> p = que.front();
        que.pop();
        int par = p.first;
        int chi = p.second;
        ans[chi] = ans[par] + score[chi];
        check[chi] = true;
        for(auto c : child[chi]){
            if(!check[c]) que.push({chi,c});
        }
    }
    for(int i = 1; i <= N ; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
