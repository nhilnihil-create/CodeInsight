#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n+1);
    vector<ll> b(m+1);
    a[0]=0;
    b[0]=0;
    rep1(i,n){
        ll p;
        cin>>p;
        a[i]=a[i-1]+p;
    }
    rep1(i,m){
        ll q;
        cin>>q;
        b[i]=b[i-1]+q;
    }
    int ans=0;
    int v=m+1;
    rep(i,n+1){
        ll judge=k-a[i];
        if(judge<0) break;
        bool decide=false;
        per(j,v){
            if(judge>=b[j]) {
                v=j+1;
                decide=true;
                break;
            }
        }
        if(decide) ans=max(ans,i+v-1);
    }

    cout<<ans<<endl;

    
}