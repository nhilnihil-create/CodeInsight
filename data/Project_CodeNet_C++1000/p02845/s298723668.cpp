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
    ll n,ans=1; cin>>n;
    vector<ll> a(n,0),c(3,-1);
    rep(i,n) cin>>a[i];
    rep(i,n){
        int cnt=0;
        rep(j,3)if(a[i]==c[j]+1) cnt++;
        ans=(ans*cnt)%MOD;
        rep(j,3){
            if(a[i]==c[2-j]+1){
                c[2-j]=a[i];
                break;
            }
        }
    }
    cout<<(MOD+ans)%MOD<<endl;
}