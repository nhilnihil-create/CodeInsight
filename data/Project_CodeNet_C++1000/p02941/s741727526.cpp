#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
int main(){
int n;
cin>>n;
vector<ll> a(n),b(n);
for(int i=0;i<n;i++)cin>>a.at(i);
for(int i=0;i<n;i++)cin>>b.at(i);
ll cnt=0;
priority_queue<P> pq;
for(int i=0;i<n;i++)if(b[i]!=a[i])pq.push(P(b[i]-a[i],i));
while(!pq.empty()){
    P now=pq.top();
    pq.pop();
    ll bet=b[(now.se-1+n)%n]+b[(now.se+1)%n],nowcnt;
    nowcnt=(b[now.se]-a[now.se])/bet;
    cnt+=nowcnt;
    b[now.se]-=bet*nowcnt;
    if(nowcnt<=0){cout<<-1<<endl;return 0;}
    if(b[now.se]==a[now.se])continue;
    pq.push(P(b[now.se]-a[now.se],now.se));
}
cout<<cnt<<endl;
}
