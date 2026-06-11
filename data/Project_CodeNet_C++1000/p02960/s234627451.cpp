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

ll d[13][100001]={};

int main() {
	string s;
	cin>>s;
	int n;
	n=s.size();
	if(s[0]=='0')d[0][0]=1;
	if(s[0]=='1')d[1][0]=1;
	if(s[0]=='2')d[2][0]=1;
	if(s[0]=='3')d[3][0]=1;
	if(s[0]=='4')d[4][0]=1;
	if(s[0]=='5')d[5][0]=1;
	if(s[0]=='6')d[6][0]=1;
	if(s[0]=='7')d[7][0]=1;
	if(s[0]=='8')d[8][0]=1;
	if(s[0]=='9')d[9][0]=1;
	if(s[0]=='?'){
		rep(i,10)d[i][0]=1;
	}

	rep(i,n-1){
		int d2=0;
		if(s[i+1]=='0')d2=0;
		if(s[i+1]=='1')d2=1;
		if(s[i+1]=='2')d2=2;
		if(s[i+1]=='3')d2=3;
		if(s[i+1]=='4')d2=4;
		if(s[i+1]=='5')d2=5;
		if(s[i+1]=='6')d2=6;
		if(s[i+1]=='7')d2=7;
		if(s[i+1]=='8')d2=8;
		if(s[i+1]=='9')d2=9;
		if(s[i+1]=='?'){
			rep(j,13){
				rep(k,10){
					int j2=(j*10+k)%13;
					d[j2][i+1]+=d[j][i];
				}
			}
		}else{
			rep(j,13){
				int j2=(j*10+d2)%13;
				d[j2][i+1]+=d[j][i];
			}
		}
		
		rep(j,13)d[j][i+1]%=1000000007;
	}
	cout<<d[5][n-1]<<endl;
	return 0;
}
