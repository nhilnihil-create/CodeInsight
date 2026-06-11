#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e12;
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
    vector<int> check(N+1,0);
    for(int i = 0; i < M; i++){
        int a;
        cin >> a;
        check[a] = 1;
    }
    ll memo[N+1];
    for(int i = 0; i <= N; i++) memo[i] = 0;
    memo[N] = 1;
    for(int i = N-1; i >= 0; i--){
        if(check[i] == 1) continue;
        bool ex = false;
        if(i + 1 <= N){
            if(check[i+1] != 1){
                ex = true;
                memo[i] = (memo[i] + memo[i+1]) % MOD;
            }
        }
        if(i + 2 <= N){
            if(check[i+2] != 1){
                ex = true;
                memo[i] = (memo[i] + memo[i+2]) % MOD;
            }
        }
        if(!ex){
            memo[0] = 0;
            break;
        }
    }
    cout << memo[0] << endl;
    return 0;
}
