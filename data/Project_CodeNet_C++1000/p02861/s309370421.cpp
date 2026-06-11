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

typedef vector<pair<int,int>> vpi;
vpi points(8);
int n;

ld brute(ld len,int np,vi vis,pair<int,int> pp){
	if(np==n){
		return len;
	}
	else{
		int h=0;
		ld sum=0;
		for(int i=0;i<n;i++){
			if(vis[i]){
				h++;
				ld cl;
				if(pp.f==1001 && pp.s==1001){
					cl=0;
				}
				else{
					cl=sqrt((points[i].f-pp.f)*(points[i].f-pp.f)+(points[i].s-pp.s)*(points[i].s-pp.s));
				}
				vis[i]=0;
				sum+=brute(cl+len,np+1,vis,points[i]);
				vis[i]=1;
			}
		}
		return sum/h;
	}
}

void solve(){
	cin>>n;
	rep(i,0,n){
		int x,y;
		cin>>x>>y;
		points[i]=mk(x,y);
	}
	vi vis(n,1);
	cout<<brute(0,0,vis,mk(1001,1001))<<ln;
}

int main(){
	boost_io;
	cout<<fixed;
	cout<<setprecision(9);
	solve();
	return 0;
}