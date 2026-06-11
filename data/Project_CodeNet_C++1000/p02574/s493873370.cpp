#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 1000007
#define MO (int(1e9)+7)
int a[MAXN];
int gcd(int a, int b) {
	return b==0?a:gcd(b,a%b);
}
int v[MAXN];
bool vis[MAXN];
inline void db() {
	memset(v,0,sizeof v);
	for(int i=2; i<=1000000; i++) if(!v[i]) {
		v[i]=i;
		for(long long j=1ll*i*i; j<=1000000; j+=i) {
			v[j]=i;
		}
	}
}
int n;
inline bool vali() {
	memset(vis,0,sizeof vis);
	for(int i=0; i<n; i++) {
		int x=a[i];
		while(x>1) {
			if(vis[v[x]]) {
				return false;
			}
			vis[v[x]]=true;
			int ss=v[x];
			do { x/=ss; }while(x%ss==0);
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	db();
	cin >> n;
	int g=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		g=gcd(g,a[i]);
	}
	if(g==1) {
		if(vali()) {
			cout << "pairwise coprime\n";
		} else {
			cout << "setwise coprime\n";
		}
	} else {
		cout << "not coprime\n";
	}

}
