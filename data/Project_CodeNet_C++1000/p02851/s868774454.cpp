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

int main(){
    ll n,k,ans=0,sum=0; cin>>n>>k;
    vector<ll> a(n,0);
    rep(i,n) cin>>a[i];
    map<ll,ll> m;
    m[0]=1;
    queue<ll> que;
    que.push(0);
    rep(i,n){
        sum+=a[i];
        ll num=(sum-i-1)%k;
        num=(num+k)%k;
        que.push(num);
        if(i>=k-1){
            m[que.front()]--;
            que.pop();
        }
        if(m.count(num)) ans+=m[num];
        else m[num]=0;
        m[num]++;
    }
    cout<<ans<<endl;
}