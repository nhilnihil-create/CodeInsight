//Powerful Discount Tickets

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
using p = pair<ll, string>;
using garph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n,m;cin>>n>>m;
    priority_queue<int>a;
    rep(i,0,n){
        int c;cin>>c;
        a.push(c);
    }
    rep(i,0,m){
        int c = a.top();
        a.pop();
        c/=2;
        a.push(c);
    }
    int sum = 0;
    while(!a.empty()){
        int c = a.top();
        a.pop();
        sum += c;
    }
    cout<<sum<<nnn;
    return 0;
}