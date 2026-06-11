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
    ll s;
    cin >> s;
    if(s <= 1000000000){
        cout << 0 << " " << 0 << " " << 1 << " "  << 0 << " " << 1 << " " << s << endl;
    }
    else{
        ll x,y;
        if(s % 1000000000 == 0){
            y = s / 1000000000; x = 0;
        } 
        else{
            y = (s / 1000000000) + 1; x = 1000000000 * y - s;
        }
        cout << "0 0 " << "1000000000 1 "<< x << " " << y << endl;
    }
    return 0;
}
