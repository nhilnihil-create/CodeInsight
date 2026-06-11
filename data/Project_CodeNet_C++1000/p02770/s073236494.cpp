#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

int main() {
    int k,q; cin>>k>>q;
    vector<int> d(k);
    for (int i = 0; i < k; ++i) {
        cin>>d[i];
    }

    for (int i = 0; i < q; ++i) {
        ll n,x,m; cin>>n>>x>>m;
        vector<ll> cnt(k+1,0),ruiseki(k+1,0);
        for (int j = 0; j < k; ++j) {
            cnt[j+1]=cnt[j]+((d[j]%m==0)?1:0);
            ruiseki[j+1]=ruiseki[j]+d[j]%m;
        }
        ll ans=(n-1ll)/k*cnt[k];
        ans+=cnt[(n-1ll)%k];

        ll last=x+(n-1ll)/k*ruiseki[k];
        //cout<<last<<endl;
        last+=ruiseki[(n-1ll)%k];
        //cout<<last<<endl;
        ll cnt2=last/m-x/m;


        cout<<n-1-ans-cnt2<<endl;
    }

    return 0;

}
