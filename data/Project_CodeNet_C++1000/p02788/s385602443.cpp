#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll N,D,A;
    cin >> N >> D >> A;
    vector<pair<ll,ll>> XH(N);
    for(ll i = 0; i < N; i++){
        cin >> XH.at(i).first >> XH.at(i).second;
        XH.at(i).second = 1 + (XH.at(i).second -1) / A;
    }
    sort(XH.begin(), XH.end());
    
    ll zero = 0;
    vector<ll> range(N); //iを左端にしたとき、range[i]までダメージを受ける。
    for(ll i = 0; i < N; i++){
        range.at(i) = lower_bound(XH.begin(), XH.end(), make_pair(XH.at(i).first + 2*D + 1, zero)) - XH.begin();
        range.at(i)--;
    }
    vector<ll> leftrange(N); //iを右端にしたとき、leftrange[i]+1までダメージを受ける。
    for(ll i = 0; i < N; i++){
        leftrange.at(i) = lower_bound(XH.begin(), XH.end(), make_pair(XH.at(i).first - 2*D, zero)) - XH.begin();
        leftrange.at(i) = leftrange.at(i) - 1;
    }

    ll tmp = 0;
    vector<ll> bomb(N+1,0); //i+1を左端にして爆発させる爆弾の数の累積和
    for(ll i = 1; i < N+1; i++){
        bomb.at(i) = bomb.at(i-1);
        if(XH.at(i-1).second <= bomb.at(i) - bomb.at(leftrange.at(i-1) + 1)){
            continue;
        }
        else{
            tmp = XH.at(i-1).second - bomb.at(i) + bomb.at(leftrange.at(i-1) + 1);
            bomb.at(i) += tmp;
        }
    }

    
    printf("%lld\n", bomb.at(N));
}