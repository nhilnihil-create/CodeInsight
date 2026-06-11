#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const int PI = acos(-1);
int main(){
	int n,m;cin>>n>>m;
	vi x[100005];
	rep(i,n){
		int a,b;
		cin>>a>>b;
		x[a].push_back(b);
	}
	priority_queue<int>q;
	ll ans =0 ;
	rep(i,m+1){
		for(int a:x[i])q.push(a);
		if(q.size()){
			ans+=q.top();
			q.pop();
		}
	}
	cout<<ans<<endl;
}