#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1000000000000000000;

signed main(){
    int n;
    cin>>n;
    V<ll> a(n);
    cinf(n,a);
    sort(all(a));
    ll ans=0;
    V<P> b;
    int l,r;
    if(a[n-1]<=0){
        l=n-2;r=n-1;
        ll cnt=a[n-1];
        while(true){
            b.push_back(P(cnt,a[l]));
            cnt-=a[l];
            if(l==0) break;
            l--;
        }
        cout<<cnt<<endl;
        for(P pp:b) cout<<pp.ft<<' '<<pp.sc<<endl;
    }else if(a[0]>=0){
        r=n-1;
        ll cnt=a[0];
        while(true){
            if(r>1){
                b.push_back(P(cnt,a[r]));
                cnt-=a[r];
            }
            else{
                b.push_back(P(a[1],cnt));
                cnt=a[r]-cnt;
            }
            if(r==1) break;
            r--;
        }
        cout<<cnt<<endl;
        for(P pp:b) cout<<pp.ft<<' '<<pp.sc<<endl;
    }else{
        if(n==2){
            cout<<a[1]-a[0]<<endl;
            cout<<a[1]<<' '<<a[0]<<endl;
        }else{
            int u=lb(all(a),0)-a.begin();
            bool ok=0;
            r=n-1;
            ll cnt=a[0];
            if(u==n-1){
                ok=1;
                r=n-2;
                cnt=a[n-1];
            }
            while(true){
                if(!ok){
                    b.push_back(P(cnt,a[r]));
                    cnt-=a[r];
                    if(r==u+1){
                        a[0]=cnt;
                        cnt=a[u];
                        r=u-1;
                        ok=1;
                        continue;
                    }
                    r--;
                }else{
                    b.push_back(P(cnt,a[r]));
                    cnt-=a[r];
                    if(r==0) break;
                    r--;
                }
            }
            cout<<cnt<<endl;
            for(P pp:b) cout<<pp.ft<<' '<<pp.sc<<endl;
        }
    }
}