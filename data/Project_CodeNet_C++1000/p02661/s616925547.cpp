#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
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
const double PI = acos(-1);

int main(){
	ll n;cin>>n;
	vl a(n),b(n);
	rep(i,n){
		cin>>a[i]>>b[i];
	}
	sort(been(a));
	sort(been(b));
	if(n%2){
		cout<<b[(n)/2]-a[(n)/2]+1<<endl;
	}
	else{
		cout<<(b[n/2]+b[n/2-1])-(a[n/2]+a[n/2-1])+1<<endl;
	}
	
}