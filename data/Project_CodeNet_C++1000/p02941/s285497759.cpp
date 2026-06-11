// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=2e5+10,mod=998244353;
const ll inf=1e18;

int a[maxn], b[maxn], n;
queue<int> q;

int Sum(int i){
    return b[(i+n-1)%n] + b[(i+1)%n];
}
void Do(int i){
    int num=Sum(i);
    if(b[i]>num && b[i]-num>=a[i]) q.push(i);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    cin>>n;

    for(int i=0;i<n;i++)
	cin>>a[i];
    for(int i=0;i<n;i++)
	cin>>b[i];
    for(int i=0;i<n;i++)
	if(b[i]<a[i]) return cout<<-1<<endl,0;
    for(int i=0;i<n;i++)
	Do(i);
    
    ll ans=0;

    while(sz(q)){
	int i=q.front();
	q.pop();
	int x=(b[i]-a[i])/Sum(i);
	ans+=x, b[i]-=x*Sum(i);
	Do((i+n-1)%n), Do((i+1)%n);
    }
    for(int i=0;i<n;i++)
	if(a[i]!=b[i]) return cout<<-1<<endl,0;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
