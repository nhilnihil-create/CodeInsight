#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include<set>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define P(p) cout<<(p)<<endl;
#define p(p) cout<<(p)<<" ";
#define pb push_back
#define mp make_pair
#define INF 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef long long ll;

int dy[8]={1,1,1,0,0,-1,-1,-1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
struct S{
	int a,b,c;
};
bool asc(const S& left,const S& right){
	return left.c > right.c;
}
int n,m,l,r;
vi a;
int dp[100001];
void input(){
	cin>>n;
	int tmp;
	rep(i,n){
		cin>>tmp;
		a.pb(tmp);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	input();
	//memset(dp,-1,sizeof(dp));
	int ans=0,tmp=0;
	/*rep(i,n){
		dp[i]=1;
		rep(j,i){
			if(a[i]>a[j]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);	
	}*/
	/*rep(i,n)dp[i]=INF;
	dp[0]=a[0];
	REP(i,1,n){
		rep(j,i+1){
			if(dp[j-1]<a[i]){
				dp[j]=min(dp[j],a[i]);
				ans=max(ans,j+1);
			}
		}
	}*/
	rep(i,n)dp[i]=INF;
	rep(i,n){
		*lower_bound(dp,dp+n,a[i])=a[i];
	//	rep(j,n)p(dp[j]);
	//	cout<<endl;
	}
	cout<<(lower_bound(dp,dp+n,INF)-dp)<<endl;
	return 0;
}