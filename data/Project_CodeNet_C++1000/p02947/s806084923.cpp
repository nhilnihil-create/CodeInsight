#include<bits/stdc++.h> 
//#define <- プログラムの文字列を置換する
//typedef <- 新しい型に名前を付けるためのキーワード

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const long long MOD = 1e9 + 7;
const long long INF = 1e15;
const int INF_INT = 1e9;

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
    map<string,ll> m;
    for(int i = 0; i < N; i++){
        string a;
        cin >> a;
        sort(a.begin(),a.end());
        m[a]++;
    }
    ll ans = 0;
    auto ite = m.begin();
    for(;ite != m.end(); ite++){
        ans += ite->second * (ite->second - 1) / 2 ;
    }
    cout << ans << endl;
    return 0;
}
