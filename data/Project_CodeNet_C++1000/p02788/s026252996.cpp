#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;



int main(){
    ll n,d,a;cin>>n>>d>>a;
    queue<pair<ll,ll> > q;
    ll cn=0;
    vector<pair<ll,ll> > e(n);
    rep(i,0,n)cin>>e[i].first>>e[i].second;
    sort(e.begin(),e.end());
    ll dm=0;
    rep(i,0,n){
        while(q.size()&&q.front().first<e[i].first){
            dm-=q.front().second;
            q.pop();
        }
        ll nowh=e[i].second-dm;
        if(nowh>0){
            dm+=(nowh+a-1)/a*a;
            q.push(make_pair(e[i].first+2*d,(nowh+a-1)/a*a));
            cn+=(nowh+a-1)/a;
        }
        
    }
    cout<<cn<<endl;
}
    







