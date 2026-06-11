//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};



int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    in n,k;
    cin>>n>>k;
    vector<in> a(n);
        rep(i,n) cin>>a.at(i);
    vector<in> full(n);
    in cnt=0ll;
    rep(i,n){
        cnt=0ll;
        rep(j,n){
            if(i==j) continue;
            if(a[i]>a[j]) cnt ++;
        }
        full[i]=cnt;
    }
    vector<in> part(n,0ll);
    rep(i,n){
        cnt=0ll;
        REP(j,i+1ll,n){
            if(a[i]>a[j]) cnt ++;
        }
        part[i]=cnt;
    }
    in ans=0ll;
    rep(i,n) ans=(ans+k*part[i])%MOD;
    k=(k-1)*k/2ll%MOD;
    rep(i,n) ans=(ans+full[i]*k)%MOD;
    cout<<ans<<endl;
}