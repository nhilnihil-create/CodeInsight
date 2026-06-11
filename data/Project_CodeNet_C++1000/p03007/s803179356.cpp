#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    sort(all(a));
    if(n==2){
        cout<<a[1]-a[0]<<endl;
        cout<<a[1]<<' '<<a[0]<<endl;
        return 0;
    }
    if(a[n-1]<=0){
        ll m=0;
        rep(i,n-1){
            m+=abs(a[i]);
        }
        m-=abs(a[n-1]);
        cout<<m<<endl;
        cout<<a[n-1]<<' '<<a[0]<<endl;
        ll s=a[n-1]-a[0];
        REP(i,1,n-1){
            cout<<s<<' '<<a[i]<<endl;
            s-=a[i];
        }
    }else if(a[0]>=0){
        ll m=0;
        REP(i,1,n){
            m+=a[i];
        }
        m-=a[0];
        cout<<m<<endl;
        ll s=a[0]-a[n-1];
        cout<<a[0]<<' '<<a[n-1]<<endl;
        ll p=a[n-2];
        REP(i,1,n-2){
            if(a[i]<=0){
                cout<<p<<' '<<a[i]<<endl;
                p-=a[i];
            }else{
                cout<<s<<' '<<a[i]<<endl;
                s-=a[i];
            }
        }
        cout<<p<<' '<<s<<endl;
    }else{
        ll m=0;
        rep(i,n){
            m+=abs(a[i]);
        }
        cout<<m<<endl;
        ll s=a[0];
        ll p=a[n-1];
        REP(i,1,n-1){
            if(a[i]<=0){
                cout<<p<<' '<<a[i]<<endl;
                p-=a[i];
            }else{
                cout<<s<<' '<<a[i]<<endl;
                s-=a[i];
            }
        }
        cout<<p<<' '<<s<<endl;
    }
}