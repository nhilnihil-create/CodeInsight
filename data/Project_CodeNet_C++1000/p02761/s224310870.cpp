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
	int n,m;
	cin>>n>>m;
	vi s(m);
	vi a(n,-1);
	rep(i,0,m){
		int h;
		cin>>s[i]>>h;
		if(s[i]==1 && h==0 && n!=1){
			cout<<-1<<ln;
			return;
		}
		if(a[s[i]-1]==-1 || a[s[i]-1]==h){
			a[s[i]-1]=h;
		}
		else{
			cout<<-1<<ln;
			return;
		}
	}
	int h=1;
	if(n==1)
		h=0;
	rep(i,0,n){
		if(a[i]==-1){
			cout<<h;
			h=0;
		}
		else{
			cout<<a[i];
			h=0;
		}
	}
	cout<<ln;
}	

int main(){
	boost_io;
	cout<<setprecision(10);
	solve();
	return 0;
}
