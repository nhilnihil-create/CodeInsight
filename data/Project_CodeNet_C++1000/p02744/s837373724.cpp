//String Equivalence

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

vector<string>ans;

void f(string s,int n){
    if(s.size()==n){ans.pb(s);return;}
    int mx=0;
    rep(i,0,s.size())mx=max(mx,(ll)s[i]-'a');
    rep(i,0,mx+2){
        string t=s;
        t.pb('a'+i);
        f(t,n);
    }
    return;
}

signed main (){
    int n;cin>>n;
    f("a",n);
    sort(range(ans));
    for(auto i:ans)cout<<i<<nnn;
    return 0;
}