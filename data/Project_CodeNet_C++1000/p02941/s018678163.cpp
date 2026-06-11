#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
priority_queue<pii> pq;
int n,a[200005],b[200005],ans;
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        cin>>b[i];
        if(b[i]<a[i]){
            cout<<-1<<endl;
            return;
        }
        pq.push({b[i],i});
    }
    while(!pq.empty()){
        pii d=pq.top();
        pq.pop();
        int h=max(b[(d.y-1+n)%n],b[(d.y+1)%n]);
        int del=(b[(d.y-1+n)%n]+b[(d.y+1)%n]);
        int q=(d.x-h+del-1)/del;
        if(d.x-q*del<a[d.y]){
            q=(d.x-a[d.y])/del;
            if(d.x-q*del!=a[d.y]){
                cout<<-1<<endl;
                return;
            }
        }
        ans+=q;
        b[d.y]=d.x-q*del;
        if(b[d.y]!=a[d.y]) pq.push({b[d.y],d.y});
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}