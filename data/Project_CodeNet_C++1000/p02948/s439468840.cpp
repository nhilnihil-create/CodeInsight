// lcmとか__builtin_popcountとかはg++ -std=c++17 default.cppみたいなかんじで

#include <bits/stdc++.h>
#define mod 1000000007
#define INF LLONG_MAX
#define ll long long
#define ln cout<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
#define all(x) (x).begin(),(x).end()
using namespace std;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
bool comp(pair<ll, ll> a, pair<ll , ll> b) {
    // 基本はfirstで比較
    if(a.first != b.first){
         return a.first < b.first; // 昇順
        //return a.first > b.first; // 降順
    }

    // それ以外はsecondで比較
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        // どちらも同じ
        return true;
    }
}


int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll a,b,c,d,n,maxi=0,f=0,mini=INF,sum=0;
    ll h,w;
    ll m;
    cin>>n>>m;
    vector<pair<ll, ll>> p(n);
    rep(i,n) {
        cin>>a>>b;
        p[i]=make_pair(a,b);
    }
    priority_queue<ll> q;
    sort(all(p),comp);
    ll last=0;
    REP(i,1,m+1){
        while(p[last].first==i){
            q.push(p[last].second);
            last++;
        }
        if(!q.empty()){
            sum+=q.top();
            q.pop();
        }

    }

    cout<<sum<<endl;
}
