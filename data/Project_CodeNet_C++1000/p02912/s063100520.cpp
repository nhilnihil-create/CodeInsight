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
    int N,M;
    cin >> N >> M;
    priority_queue<int> q;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        q.push(a);
    }
    for(int i = 0; i < M; i++){
        int maxi = q.top();
        q.pop();
        q.push(maxi/2);
    }
    ll ans = 0;
    while(!q.empty()){
        int value = q.top();
        q.pop();
        ans += value;
    }
    cout << ans << endl;
    return 0;
}
