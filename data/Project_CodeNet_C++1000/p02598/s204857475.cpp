#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

int N,K;
int a[maxn];

bool judge(double x){
	ll cnt = 0;
	for(int i =1;i<=N;i++){
		cnt += ceil(a[i]/x)-1;
	}
	return cnt<=K;
}
void solve(){
	double l = 1,r = 1e9+10;
	for(int i = 1;i<=50;i++){
		double mid = (l+r)/2;
		if(judge(mid)) r = mid;
		else l = mid;
	}
	int ans = ceil(l);
	cout<<ans<<'\n';
}
int main(){
	// debug;
	ios;

	cin>>N>>K;
	for(int i =1;i<=N;i++) cin>>a[i];
	solve();
	
	return 0;
}
