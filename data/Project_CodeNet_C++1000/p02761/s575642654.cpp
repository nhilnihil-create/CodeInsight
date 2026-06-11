
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> p(m);
    rep(i,m) cin >> p[i].first >> p[i].second;

    //あり得る数は高々1000通りなので全部計算できる
    rep(x,1000){
        int keta = 1;
        int nx = x/10;
        //要素1、初期値はxの1の位にする
        vector<int> d(1,x%10);
        while(nx){
            keta ++;
            d.push_back(nx%10);
            nx /= 10;
        }
        if(keta != n) continue;
        bool ok =true;
        reverse(all(d));
        rep(i,m){
            if(d[p[i].first-1] != p[i].second) ok=false;
        }
        if(ok){
            cout << x << endl;
            return 0;
        }
    }
    //最後まで見つからなかったら-1
    cout << -1 << endl;
    return 0;


}