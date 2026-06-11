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
    string s;
    cin >> N >> s;
    int ans = 0;
    for(int i = 0; i < 1000; i++){
        int thr = i / 100;
        int two = (i - thr*100) / 10;
        int one = (i - thr*100) % 10;
        vector<char> check = {(char)('0' + thr),(char)('0'+ two),(char)('0'+one)};
        int count = 0;
        bool flag = false;
        for(int j = 0; j < N; j++){
            if(check[count] == s[j]) count++;
            if(count  == 3){
                flag = true;
                break;
            } 
        }
        if(flag) ans++;
    }
    cout << ans << endl;
    return 0;
}
