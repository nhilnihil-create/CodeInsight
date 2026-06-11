#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=1e9+7;
int main(){
  ll n,k;cin>>n>>k;
    vector<ll>a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    vector<ll>y(0);
    for(int i=1;i<sqrt(sum);i++){
        if(sum%i==0){
            if(sum/i!=i)y.pb(sum/i);
            y.pb(i);
        }
    }
    ll ans=1;
    for(int i=0;i<y.size();i++){
        ll s=y[i];
        priority_queue<ll>pq;
        ll ss=0;
        for(int j=0;j<n;j++){
            ss+=a[j]%s;
            pq.push(a[j]%s);
        }
        ll cnt=ss;
        for(int j=0;j<ss/s;j++){
            cnt+=(s-2*pq.top());
            pq.pop();
        }
        if(cnt<=2*k){
            ans=max(ans,y[i]);
        }
      //cout<<y[i]<<' '<<cnt<<endl;
    }
    cout<<ans<<endl;
}