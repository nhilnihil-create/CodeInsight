#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);

ll n,d,a;
vector<P> M;

int main(){
    cin >> n >> d >> a;
    vector<ll> X;
    rep(i,n){
        ll x,h; cin >> x >> h;
        M.push_back(make_pair(x,h));
        X.push_back(x);
    }
    sort(M.begin(),M.end());
    sort(X.begin(),X.end());
    
    ll res = 0;
    vector<ll> sumq(n+1,0);
    rep(i,n){
        if(i) sumq[i] += sumq[i-1];
        M[i].second -= sumq[i];
        if(M[i].second<=0) continue;
        // 攻撃回数
        ll num = (M[i].second + (a-1) )/a;
        // 与える攻撃量
        ll q = a*num;
        res += num;
        // 攻撃範囲外になったら imos っぽく -=q する
        sumq[i+1] += q;
        sumq[upper_bound(X.begin(),X.end(),X[i]+2*d)-X.begin()] -= q;
    }
    cout << res << endl;
}