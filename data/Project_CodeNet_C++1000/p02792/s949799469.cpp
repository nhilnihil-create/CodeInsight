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
ll dp2[300000][60]={};
int main() {
	int n;
	cin>>n;
	ll r=0;
	rep(i,n){
		int a1,a2;
		a1=(i+1)%10;
		a2=i+1;
		if(a1==0)continue;
		if(a2>9)a2/=10;
		if(a2>9)a2/=10;
		if(a2>9)a2/=10;
		if(a2>9)a2/=10;
		if(a2>9)a2/=10;
		if(a1==a2)r++;
		if(a2+a1*10<=n)r++;
		rep(j,10){
			if(n>=(a1*100+j*10+a2))r++;
		}
		rep(j,100){
			if(n>=(a1*1000+j*10+a2))r++;
		}
		rep(j,1000){
			if(n>=(a1*10000+j*10+a2))r++;
		}
		rep(j,10000){
			if(n>=(a1*100000+j*10+a2)){
				r++;
			}else{
				break;
			}
		}

//		cout<<i<<" "<<r<<endl;
	}
	cout<<r<<endl;
	return 0;
}
