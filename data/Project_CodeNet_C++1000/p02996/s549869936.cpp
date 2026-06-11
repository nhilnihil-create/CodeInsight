
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

typedef pair<int,int> P;
//締め切りが早い順に取り組めば良い
int main(){
    int n;
    cin >> n;
    vector<P> p(n);
    //bでソートしたいのでaをsecond、bをfirstに格納する
    rep(i,n) cin >> p[i].second >> p[i].first;
    sort(all(p));

    //経過時間を0とする
    ll t=0;
    rep(i,n){
        t += p[i].second;
        //締め切りをオーバーしていたら即時終了
        if(t > p[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;



}