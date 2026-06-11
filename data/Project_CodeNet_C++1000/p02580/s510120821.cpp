#include<bits/stdc++.h>

using namespace std;

#define forinc(a,b,c) for(int a=b, __c=c; a<=__c; ++a)
#define fordec(a,b,c) for(int a=b, __c=c; a>=__c; --a)
#define forv(a,b) for(auto &a:b)

#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(a) begin(a),end(a)
#define rall(a) rbegin(a),rend(a)
#define reset(f,x) memset(f,x,sizeof(f))
#define fasty ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))

typedef long long ll;
typedef unsigned long long ull;

const int N=3e5+5;
int h,w,n;
ii a[N];
int f[N], g[N];

int32_t main(){
    fasty;
    cin>>h>>w>>n;
    forinc(i,1,n) cin>>a[i].fi>>a[i].se;
    forinc(i,1,n) f[a[i].fi]++, g[a[i].se]++;
    int mf=0, mg=0;
    forinc(i,1,h) mf=max(mf, f[i]);
    forinc(i,1,w) mg=max(mg, g[i]);
    int cf=count(f+1, f+h+1, mf);
    int cg=count(g+1, g+w+1, mg);
    int tot=0;
    forinc(i,1,n) if(f[a[i].fi]==mf && g[a[i].se]==mg) tot++;
    if(tot==cf*cg) cout<<mf+mg-1<<'\n';
    else cout<<mf+mg<<'\n';
}
