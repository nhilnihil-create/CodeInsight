#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define FILV(x,a) fill(x.begin(),x.end(),a)
#define FILA(ar,N,a) fill(ar,ar+N,a)
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define pb push_back
#define pri(aa) cout<<(aa)<<endl
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
const ll INF=1e9+7;
const ll N = 1007;


ll LCS(string x,string y){
	ll xs,ys;
	xs=x.size();ys=y.size();
	ll dp[xs+1][ys+1];
	FOR(i,0,xs+1)FOR(j,0,ys+1)dp[i][j]=0;
	FOR(i,0,xs+1){
		FOR(j,0,ys+1){
			if(i==0||j==0)dp[i][j]=0;
			else{
				if(x[i-1]==y[j-1])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[xs][ys];
}



int main(){
	ll n;
	cin>>n;
	FOR(i,0,n){
		string x,y;
		cin>>x>>y;
		cout<<LCS(x,y)<<endl;
	}
}
