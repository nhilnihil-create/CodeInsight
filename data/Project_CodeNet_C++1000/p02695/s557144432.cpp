//Many Requirements

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll, string>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int n,m,q;
set<vector<int>>t;

void dfs(vector<int>s){
    if(s.size()==n+1){
        t.insert(s);
    }else{
        vector<int>t;
        rep(i,s[s.size()-1],m+1){
            t=s;
            t.pb(i);
            dfs(t);
        }
    }
}

signed main (){
    cin>>n>>m>>q;
    vector<int>s;
    s.pb(1);
    dfs(s);
    vector<vector<int>>r(q,vector<int>(4));
    int ans = 0;
    rep(i,0,q){
        cin>>r[i][0]>>r[i][1]>>r[i][2]>>r[i][3];
    }
    for(auto i:t){
        int c = 0;
        rep(j,0,q){
            if(i[r[j][1]]-i[r[j][0]]==r[j][2])c+=r[j][3];
        }
        ans=max(ans,c);
    }
    cout<<ans<<nnn;
    return 0;
}