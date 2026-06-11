#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,d,a;
    cin>>n>>d>>a;

    vector<pair<int,int>> pr;
    for(int i = 0; i < n; i++){
        int x,h;cin>>x>>h;
        pr.push_back({x,h});
    }
    sort(pr.begin(),pr.end());

    queue<pair<ll,ll>> q;
    ll tot = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int x = pr[i].first;
        int h = pr[i].second;
        while(q.size() && q.front().first < x){
            tot-=q.front().second;
            q.pop();
        }
        h-=tot;
        if(h>0){
         int num = (h+a-1)/a;
         ans+=num;
         int damage = num*a;
         tot+=damage;
         q.push({x+2*d,damage});
        }
    }
    cout<<ans;
}
