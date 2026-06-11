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
ll dp[300000][60]={};
ll dp2[300000][60]={};
ll a[300000];
int main() {
	int n;
	cin>>n;
	ll r=0;
	ll ndp1[60]={};
	ll ndp2[60]={};
	ll s1[60];
	s1[0]=1;
	rep(i,59)s1[i+1]=s1[i]*2;
	rep(i,n){
		cin>>a[i];
		rep(j,60){
			if((a[i]&s1[j])>0){
				ndp1[j]++;
			}else{
				ndp2[j]++;
			}
			dp[i][j]=ndp1[j];
			dp2[i][j]=ndp2[j];
		}
	}	
	rep(i,n-1){
		rep(j,60){
			if((a[i]&s1[j])>0){

				r+=(s1[j]%inf)*(dp2[n-1][j]-dp2[i][j]);
				r%=inf;
			}else{
				r+=(s1[j]%inf)*(dp[n-1][j]-dp[i][j]);
				r%=inf;
			}

		}
	}
	cout<<r<<endl;

	return 0;
}
