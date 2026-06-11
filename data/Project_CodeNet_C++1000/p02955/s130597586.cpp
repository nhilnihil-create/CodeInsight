//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    ll n,k,sum=0,cnt; cin>>n>>k;
    vector<ll> a(n,0);
    rep(i,n){
        cin>>a[i]; sum+=a[i];
    }
    vector<ll> p={1,sum};
    for(ll i=2;i*i<=sum;i++){
        if(sum%i==0){
            p.push_back(i);
            if(i*i!=sum) p.push_back(sum/i);
        }
    }
    sort(al(p));
    vector<ll> m(n,0);
    for(ll i=p.size()-1;i>=0;i--){
        sum=0; cnt=0;
        for(ll j=0;j<n;j++){
            m[j]=a[j]%p[i]; sum+=m[j];
        }
        sort(al(m));
        for(ll j=0;j<n-sum/p[i];j++){
            cnt+=m[j];
        }
        if(cnt<=k){
            cout<<p[i]<<endl;
            break;
        }
    }
}