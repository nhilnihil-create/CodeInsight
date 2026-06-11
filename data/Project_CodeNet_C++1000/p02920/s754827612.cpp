#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
set<P<int,int> > s; 
V<int> v,p;
int a[300000];
int main(){
	int n;
	cin>>n;
	int m=(1<<n);
	FOR(i,1,m)cin>>a[i];
	sort(a+1,a+m+1,greater<int>());
	FOR(i,2,m){
		s.insert(MP(a[i],i));
	}
	v.PB(a[1]);
	rep(t,0,n){
		p.clear();
		for(auto u:v){
			auto iter=s.lower_bound(MP(u,0));
			if(iter==s.begin()){
				cout<<"No";RE 0;
			}
			iter--;
			if((*iter).F>=u){
				cout<<"No";RE 0;
			}
			p.PB((*iter).F);
			s.erase(iter);
		}
		for(auto u:p)v.PB(u);
	}
	cout<<"Yes";
	RE 0;
}

