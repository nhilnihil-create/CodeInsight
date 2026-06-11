#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

vector<pii> ans;
int n; 

void add(int a,int b){
	ans.pb(mp(a,b));
}

int main(){
	read(n);
	if(n<=2)return puts("No"),0;
	int k=log(n+0.1)/log(2);
	if(n==(1<<k))return puts("No"),0;
	add(1,2),add(2,3),add(3,n+1);
	add(n+1,n+2),add(n+2,n+3);
	for(int k=4;k<n;k+=2)
		add(1,k),add(k,k+1),
		add(1,n+k+1),add(n+k+1,n+k);
	if(n%2==0){
		int p=__builtin_ctz(n);
		int t=n-(1<<p);
		add(n,1<<p);
		add(n*2,n+t+1);
	}
	puts("Yes");
	for(auto x:ans)
		printf("%d %d\n",x.fi,x.se);
	return 0;
}