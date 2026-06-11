#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int long long
#define num(a) a-'0'
#define charr(a) (a - 'A' + 1)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define maxs(a,b) if(b>a)a=b
#define mins(a,b) if(b<a)a=b
#define debug(x) cerr<<"["<<#x<<":"<<x<<"] "
#define debug2(a,b) debug(a);debug(b)
#define debug3(a,b,c) debug2(a,b);debug(c)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define print(arr) for(auto it = arr.begin();it < arr.end();it ++){cout << *it << " ";}cout << ln;
#define all(a) (a).begin(), (a).end()
#define vi vector<long long>
#define v vector
#define p pair
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define ln "\n"
typedef long double ld;
typedef double d;
using namespace std;
int modF=1e9+7;
int INF=1e11;

int fdigit(int n){
	int res;
	while(n>0){
		if(n<10)res=n;
		n/=10;
	}
	return res;
}

int ldigit(int n){
	return n%10;
}

void solve(){
	int n;
	cin>>n;
	v<vi> h(10,vi(10));
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			for(int k=1;k<=n;k++){
				if(fdigit(k)==i && ldigit(k)==j)h[i][j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<10;i++){
		for(int j=1;j<10;j++){
			ans+=h[i][j]*h[j][i];
		}
	}
	cout<<ans<<ln;
}

signed main(){
	boost_io;
	solve();
	return 0;
}