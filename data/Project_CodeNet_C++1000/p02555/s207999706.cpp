#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> ppiii;

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
    ll S;
    cin >> S;
    ll res[S + 10];
    for(int i = 0; i <= S + 10 ; i++) res[i] = 1;
    res[0] = res[1] = res[2] = 0;
    ll sub = res[3];
    for(int i = 6; i <= S + 10; i++){
        res[i] = (res[i] + sub) % MOD;
        sub = (sub + res[i - 2]) % MOD;
    }
    cout << res[S] << endl;
    return 0;
}
