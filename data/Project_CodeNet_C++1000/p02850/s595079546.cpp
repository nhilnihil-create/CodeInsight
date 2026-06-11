#include <bits/stdc++.h>
#define rep(i,n1) for(int i=0;i<n1;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<'YES'<<endl;}else{cout<<'NO'<<endl;}
#define vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
#define PI 3.141592653589793
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<int,ll> Pil;
typedef pair<ll,ll> Pll;
typedef pair<string,int> Psi;
typedef pair<Psi,int> Psii;

const ll inf=1000000007;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

vector<Pii> v[100001];
int dp[100001]={};
int dp2[100001]={};

int main() {
	int n;
	cin>>n;
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		v[a].push_back(Pii(b,i));
		v[b].push_back(Pii(a,i));		
	}
	int k=1;
	queue<int> que;
	que.push(1);
	while(!que.empty()){
		int p = que.front();que.pop();
		int c=1;
		rep(i,v[p].size()){
			int p2=v[p][i].first;
			int r2=v[p][i].second;
			if(p2>1&&dp2[p2]==0){
				if(c==dp2[p])c++;
				dp2[p2]=c;
				dp[r2]=c;
				que.push(p2);
				c++;
			}
		}
		k=max(k,c-1);
	}
	cout<<k<<endl;
	rep(i,n-1){
		cout<<dp[i]<<endl;
	}
	return 0;
}
