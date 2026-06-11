#include <bits/stdc++.h>
#define boost_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define num(a) a-'0'
#define rep(i,a,b) for(int i=a;i<b;i++)
#define maxs(a,b) if(b>a)a=b
#define mins(a,b) if(b<a)a=b
#define debug(x) cerr<<#x<<":"<<x<<" "
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define vl vector<long long int>
#define v vector
#define p pair
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
	int k;
	cin>>k;
	ll sum=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int h=1;h<=k;h++){
				sum+=__gcd(__gcd(i,j),h);
			}
		}
	}
	cout<<sum<<ln;
}	

int main(){
	boost_io;
	cout<<setprecision(10);
	solve();
	return 0;
}
