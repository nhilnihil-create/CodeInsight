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
	ld a,b;
	cin>>a>>b;
	ld l8,u8,l10,u10;
	l8=a*100/8;
	u8=(a+1)*100/8;
	l10=b*100/10;
	u10=(b+1)*100/10;
	int h=l8;
	if(l8>static_cast<int>(l8)){
		h=static_cast<int>(l8+1);
	}
	for(int i=h;i<u8;i++){
		if(i>=l10 && i<u10){
			cout<<i<<ln;
			return;
		}
	}
	cout<<-1<<ln;
}	

int main(){
	boost_io;
	cout<<setprecision(10);
	solve();
	return 0;
}
