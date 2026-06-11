#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    //各ロボットの右端、左端の情報を入れる配列
    vector<pair<ll, ll>> p(N);
    rep(i, N){
        ll x, l;
        cin >> x >> l;
        //右端の情報をfirstに、左端の情報をsecondに入れる
        p[i] = make_pair(x + l, x - l);
    }

    //右端の位置が小さい順にソート
    sort(p.begin(), p.end());

    //残すロボットの個数
    int val = 0;
    //残すと決めたロボットの中の、最も右端の情報
    ll cur = -pow(10, 9);
    rep(i, N){
        if(cur <= p[i].second){
            val++;
            cur = p[i].first;
        }
    }
    cout << val << endl;
    return 0;
}