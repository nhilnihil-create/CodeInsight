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
	int n,m;
	cin>>n>>m;
	set<int> se;
	int p;
	string s;
	int wa=0;
	int ac=0;
	vi wac(n+1,0);
	while(m--){
		cin>>p>>s;
		if(s=="WA" && se.find(p)==se.end()){
			wac[p]++;
		}
		else{
			if(se.find(p)==se.end()){
				ac++;
				se.insert(p);
				wa+=wac[p];
			}
		}
	}
	cout<<ac<<" "<<wa<<ln;
}

int main(){
	boost_io;
	solve();
	return 0;
}