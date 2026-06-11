#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   int n;cin >>n;
   vector<P>pos(n);
    for (int i = 0; i < n; ++i) {
        int x,y;cin >>x>>y;
        pos[i]={x,y};
    }
    ll ans=INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll p,q;
            ll now=0;
            if(i==j)continue;
            p=pos[i].first-pos[j].first;
            q=pos[i].second-pos[j].second;
            for (int k = 0; k < n; ++k) {
                bool flg=false;
                for (int l = 0; l <n; ++l) {
                    if(k==l)continue;
                    ll dx=pos[k].first-pos[l].first;
                    ll dy=pos[k].second-pos[l].second;
                    if(dx==p&&dy==q)flg=true;
                }
                if(!flg)now++;
            }
//            cout <<p<<" "<<q<<" "<<now<<endl;
            ans=min(ans,now);
        }
    }
    if(n==1)cout <<1<<endl;
    else {
        cout << ans << endl;
    }
}
