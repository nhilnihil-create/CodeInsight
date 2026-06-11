#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define num(a) a-'0'
#define maxself(a,b) if(b>a)a=b
#define minself(a,b) if(b<a)a=b;
#define debug(x) cout<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<long long int>
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define ln "\n"	
typedef long long int ll;
typedef long double ld;
typedef double d;
using namespace std;
ll modF=1e9+7;
ll INF=1e11;

void solve(){
	int n,k;
	cin>>n>>k;
	vi h(n);
	rep(i,0,n){
		cin>>h[i];
	}
	sort(all(h));
	ll ans=0;
	for(int i=0;i<n;i++){
		if(i<n-k){
			ans+=h[i];
		}
	}
	cout<<ans<<ln;
}

int main(){
	boost_io;
	solve();
	return 0;
}