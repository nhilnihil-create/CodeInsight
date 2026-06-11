#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
typedef long long ll;
typedef vector<int> vi;
typedef unsigned long ul;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef set<int> si;
typedef multiset<int> mi;
 
const ll INF = 1e18;
const int MOD = 1e9+7;
 
int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	//ofstream cout ("fileName.out");
	//ifstream cin ("fileName.in");
	
	int N;
	cin>>N;
	vi a(N);
	for(int i=0; i<N; ++i) cin>>a[i];
	
	sort(a.rbegin(), a.rend());
	
	priority_queue<pi> pq;
	ll ans=a[0];
	pq.push({a[1],a[0]});
	pq.push({a[1],a[0]});
	
	for(int i=2; i<N; ++i) {
		ans+=pq.top().f;
		pi temp=pq.top();
		//cout<<pq.top().f<<" "<<pq.top().s<<"\n";
		pq.pop();
		pq.push({a[i],temp.f});
		pq.push({a[i],temp.s});
	}
	
	cout<<ans<<"\n";
	return 0;
}
