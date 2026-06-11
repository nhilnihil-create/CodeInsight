#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vp=vector<pair<ll,ll>>;
int main() {
    int N;cin>>N;
    ll D,A;cin>>D>>A;
    vp enemy(N);
    for (int i = 0; i < N; i++){
        int X,H;cin>>X>>H;
        enemy[i].first=X;
        enemy[i].second=H;
    }
    sort(enemy.begin(),enemy.end());
    vector<ll> bomb_num(N,0);
    ll damage=0;
    ll ans=0;
    for (int i = 0; i < N; i++){
        ll X=enemy[i].first;
        ll H=enemy[i].second;
        damage-=A*bomb_num[i];
        H-=damage;
        H=max(H,(ll)0);
        ll n=(H+A-1)/A;
        ans+=n;
        damage+=n*A;
        auto iter=upper_bound(enemy.begin(),enemy.end(),pair<ll,ll>(X+2*D+1,0));
        int idx=distance(enemy.begin(),iter);
        if(idx!=N)bomb_num[idx]+=n;
    }
    cout<<ans<<endl;
}