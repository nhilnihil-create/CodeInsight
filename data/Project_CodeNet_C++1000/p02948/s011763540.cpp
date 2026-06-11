#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(obj) (obj).begin(),(obj).end()
typedef pair<int,int> P;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;cin>>n>>m;
    priority_queue<int> pq;
    priority_queue<P,vector<P>,greater<P>> pqmini;
    rep(i,n){
        int a,b;cin>>a>>b;
        pqmini.push(make_pair(a,b));
    }
    int tot=0;
    for(int i=1;i<=m;i++){
        while(1){
            P k=pqmini.top();
            if(k.first!=i)break;
            pq.push(k.second);
            pqmini.pop();
        if(pqmini.empty())break;            
        }
        if(pq.empty())continue;
        tot+=pq.top();pq.pop();
    }
    cout<<tot<<endl;
    return 0;
}
