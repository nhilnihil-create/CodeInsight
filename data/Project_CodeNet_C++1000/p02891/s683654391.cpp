//Connection and Disconnection

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using p = pair<char, int>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    string s;int k;cin>>s>>k;
    vector<p>t;
    t.pb(mp(s[0],1));
    rep(i,1,s.size()){
        if(s[i]==s[i-1]){
            t[t.size()-1.].second++;
        }else{
            t.pb(mp(s[i],1));
        }
    }
    int ans = 0;
    if(t.size()==1){
        ans = t[0].second*k/2;
    }else if(t[0].first==t[t.size()-1].first){
        int  c = (t[0].second+t[t.size()-1].second)/2;
        ans += c*(k-1);
        ans += t[0].second/2+t[t.size()-1].second/2;
        rep(i,1,t.size()-1){
            int c = t[i].second/2;
            ans += c*k;
        }
    }else{
        rep(i,0,t.size()){
            int c = t[i].second/2;
            ans += c*k;
        }
    }
    cout<<ans<<nnn;
    return 0;
}