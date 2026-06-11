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
    int N;
    cin >> N;
    priority_queue<double,vector<double>,greater<double> > que;
    for(int i = 0; i < N; i++){
        double a;
        cin >> a;
        que.push(a);
    }
    while(que.size() != 1){
        double a,b;
        a = que.top();que.pop();
        b = que.top();que.pop();
        que.push((a+b) / 2);
    }
    cout << que.top() << endl;
    return 0;
}
