//Lunlun Number

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

vector<int>a;

void dfs(string s){
    if(s.size()>10)return;
    int n = s.size();
    rep(i,(s[n-1]=='0'?0:-1),(s[n-1]=='9'?1:2)){
        string t = s;
        t.pb(s[n-1]+i);
        a.pb(stoll(t));
        dfs(t);
    }
}
signed main (){
    rep(i,1,10){
        a.pb(i);
        dfs(to_string(i));
    }
    sort(range(a));
    int k;cin>>k;
    cout<<a[k-1]<<nnn;
    return 0;
}