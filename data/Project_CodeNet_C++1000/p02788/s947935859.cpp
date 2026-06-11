#include <bits/stdc++.h>
#define ll long long
#define pq priority_queue
using namespace std;
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
const ll MAX=510000;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    ll N,D,A,B=0,cnt=0;
    cin>>N>>D>>A;
    vector<pair<ll,ll>> p(N);
    queue<pair<ll,ll>> q;
    pair<ll,ll> y;
    for(ll i=0;i<N;i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p.begin(),p.end());
    for(ll i=0;i<N;i++){
        while(q.size()){
            pair<ll,ll> d;
            d=q.front();
            if(d.first>=p[i].first) break;
            if(d.first<p[i].first){
                q.pop();
                B-=d.second*A;
            }
        }
        p[i].second-=B;
        //cout<<i<<" "<<p[i].second<<endl;
        if(p[i].second<=0) continue;
        ll b=p[i].second/A;
        if(p[i].second%A!=0) b++;
        q.push(pair<ll,ll>(p[i].first+2*D,b));
        B+=b*A;
        cnt+=b;
    }
    cout<<cnt<<endl;
}