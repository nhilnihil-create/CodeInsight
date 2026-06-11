#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#include <cstdlib> 
#include <math.h>
#include<cstdio>
#include<cstring>
#define FOR(I, A, B) for (ll I = (A); I <= (B); I++)
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(ll i=0;i<n;i++)
#define sz(a) ll((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define dbg(x) cout << #x << " = " << x << endl
#define dbg2(x,y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define dbg3(x,y,z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define dbg4(x,y,z,q) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << ", " << #q << " = " << q << endl
#define scan(char_array) scanf("%[^\n]s",&char_array);
const ll MOD=1000000007;

int main(){
	ll n,m;
	cin>>n>>m;
	ll a[n+1];
	ll b[m+1];
	FOR(i,1,n) cin>>a[i];
	FOR(i,1,m) cin>>b[i];
	ll dp[n+1][m+1];
	FOR(i,0,m) dp[0][i]=0;
	FOR(i,0,n) dp[i][0]=0;
	FOR(i,1,n){
		FOR(j,1,m){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]+MOD)%MOD;
			dp[i][j]=(dp[i][j]-dp[i-1][j-1]+MOD)%MOD;
			if(a[i]==b[j]) dp[i][j]=(dp[i][j]+1+dp[i-1][j-1]+MOD)%MOD;
			
		}
	}
	cout<<(dp[n][m]+1)%MOD<<endl;
}