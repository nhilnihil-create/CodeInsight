// 
// 
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define is_in(i, s) (s.find(i) != s.end())
#define all(x) (x).begin(),(x).end()
#define outl(x) cout<<x<<endl
#define outsp(x) cout<<x<<" "
typedef long long ll;
typedef pair<int,int> P;


#define MAX_N 100005
int n;
ll a[MAX_N];
ll b[MAX_N];

const ll INF=1e18;



int main() {
	cin >> n;
	ll sum=0;
	rep(i,n+1){
		cin >> a[i];
		sum += a[i];
	}
	if(n==0){
		if(a[0]==1){
			outl(1);
		}else{
			outl(-1);
		}
		return 0;
	}
	if(a[0]>0 && n>0){
		outl(-1);
		return 0;
	}
	ll ans = 1;
	ll b=1;
	sum -= a[0];
	for(int i=1;i<n;i++){
		sum -= a[i];
		b = min(sum,2*b-a[i]);
		if(b<0){
			outl(-1);
			return 0;
		}
		ans += b+a[i];
	}
	if(b<(a[n]+1)/2 || a[n]<b){
		outl(-1);
		return 0;
	}
	ans += a[n];



	outl(ans);
    return 0;
}

