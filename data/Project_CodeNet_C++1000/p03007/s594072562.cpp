#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

#define pii pair<int,int>
#define x first
#define y second

int n,res;
vector<int> a,b;
vector<pii> ans;

signed main(){
	read(n);
	for(int i=1,x;i<=n;i++) read(x),x>=0?a.push_back(x):b.push_back(-x);
	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());
	if(b.empty()){
		if(a.size()==2) res=a[0]-a[1],ans.emplace_back(a[0],a[1]);
		else{
			for(int i=1;i<a.size()-1;i++) ans.emplace_back(a[n-1],a[i]),a[n-1]-=a[i];
			ans.emplace_back(a[0],a[n-1]);
			res=a[0]-a[n-1];
		}
		write(res);
	}
	else if(a.empty()){
		for(int i=0;i<n;i++) b[i]=-b[i];
		for(int i=0;i<b.size()-1;i++) ans.emplace_back(b[n-1],b[i]),b[n-1]-=b[i];
		write(b[n-1]);
	}
	else{
		for(int i=1;i<a.size();i++){
			ans.emplace_back(-b[0],a[i]);
			b[0]+=a[i];
		}
		for(int i=0;i<b.size();i++){
			ans.emplace_back(a[0],-b[i]);
			a[0]+=b[i];
		}
		write(a[0]);
	}
	for(auto x:ans) printf("\n%d %d",x.x,x.y);
}