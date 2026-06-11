#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<'YES'<<endl;}else{cout<<'NO'<<endl;}
#define vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<int,ll> Pil;
typedef pair<ll,ll> Pll;
typedef pair<string,int> Psi;
typedef pair<Psi,int> Psii;

const int inf=1000000000;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

vi vec[200001];
int x[200001]={};
int dp[200001];
int main() {
	int r=0;
	string s,t;
	cin>>s>>t;
	if(s[0]==t[0])r++;
	if(s[1]==t[1])r++;
	if(s[2]==t[2])r++;
	cout<<r<<endl;
	return 0;
}
