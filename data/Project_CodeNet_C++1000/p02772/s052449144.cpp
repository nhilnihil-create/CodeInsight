#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define Blue ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i,a,n) for(int i=a;i<n;++i)
typedef vector<int> vi;
typedef long long ll;
const int mod=1e9+7;
 
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

void solve(){
	int n;
	cin>>n;
	vi a(n);
	bool ok=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(!(a[i]&1)){
			if(!(a[i]%3==0 || a[i]%5==0))ok=0;
		}
	}
	cout<<(ok?"APPROVED":"DENIED");
 
}
 
 
int main(){
	Blue;
	int test=1;
	//cin>>test;
	while(test--)
		solve();
	return 0;
}