#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#define _start  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb 		push_back
#define ss 		second
#define ff 		first
#define ll		long long
#define int     long long
#define mk      make_pair
#define ld 		long double
#define vi 		vector<int>
#define pi		pair<int,int>
#define mod 	1000000007
#define pqg     priority_queue<int>
#define pqs     priority_queue<int,vi,greater<int> >
#define forn(n) for(int i=0;i<n;i++)
#define w(t) 	int t; cin>>t; while(t--)
#define kick(t) int t; cin>>t; for(int p=0;p<t;p++)
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> oset;
ll powmod(ll base,ll exp,ll MOD=mod){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
ll mul_inv(ll a,ll b = mod) {ll t1=a,t2=b,t3,v1=1,v2=0,v3;while(t2!=1){ll x=t1/t2;t3=t1-x*t2;v3=v1-x*v2;t1=t2,t2=t3;v1=v2,v2=v3;}return(v2+b)%b;}

const int MAX=300005;
int xs[MAX],ys[MAX];

int32_t main(){
    _start
    int h,w,m;
    cin>>h>>w>>m;

    map<pi,int> points;
    int xmax=0,ymax=0;
    forn(m) {
        int a, b;
        cin >> a >> b;
        xs[a]++;
        ys[b]++;
        points[mk(a,b)]=i;
        xmax=max(xmax,xs[a]);
        ymax=max(ymax,ys[b]);
    }
    vector<int> xmx,ymx;
    for(int i=1;i<=h;i++) {
        if(xs[i]==xmax){
            xmx.pb(i);
        }
    }
    for(int i=1;i<=w;i++) {
        if(ys[i]==ymax){
            ymx.pb(i);
        }
    }
    int mx=xmax+ymax-1;
    for(auto x:xmx){
        for(auto y:ymx){
            if(!points.count(mk(x,y))){
                mx++;
                break;
            }
        }
        if(mx==xmax+ymax)
            break;
    }
    cout<<mx;
}