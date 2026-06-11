#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); ++i)
 
constexpr double PI = acos(-1);
//既に訪れているか(中身は{0,1}しか入れないのでbool的な扱い)
int alre[1000000];
int main() {
    ll n,k;
    cin >> n >> k;
    
    vector<int> g(n+1,0);
    vector<int> log;
    
    int a;
    int nowPos;
    
    rep(i,n) {
        cin >> a;
        g.at(i+1) = a;
    }
    //町1からスタート
    nowPos = 1;
    log.emplace_back(1);
    
    ll s,flag,loop;
    
    s = flag = loop = 0;
    //1～kまで繰り返す
    rep(i,k+1) {
        int ii = i + 1;
        //次の町へテレポート
        nowPos = g.at(nowPos);
        //logを残す
        log.emplace_back(nowPos);
        //訪れるのが2回目だったら最初に訪れた位置との差分でk-sをmodする
        //if文では0でfalse、0以外でtrueとなる(※言語差あり)
        if(flag == 0 && alre[nowPos]) {
            s = alre[nowPos];
            loop=(k-s)%(ii-s);
            flag=true;
            break;
        }
        alre[nowPos]=ii;
    }
    if(!flag) cout << log.at(k) << "\n";
    else{
        nowPos = log.at(s+loop);
        cout << nowPos << "\n";
    }
    return 0;
}