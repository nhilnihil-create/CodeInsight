#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int f[N][2],pre[N][2];char s[N];
void solve(int n,int pos){
	if(n==0) return;
	solve(n-1,pre[n][pos]);
	if(pos==0) cout<<"P";
	else cout<<"D";
}
int main(){
	cin>>(s+1);int n=strlen(s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='P'){
			f[i][0]=max(f[i-1][0],f[i-1][1]);
			pre[i][0]=(f[i][0]==f[i-1][1]);
			f[i][1]=-N;
		}
		if(s[i]=='D'){
			f[i][0]=-N;
			f[i][1]=max(f[i-1][0]+2,f[i-1][1]+1);
			pre[i][1]=(f[i][1]==f[i-1][1]+1);
		}
		if(s[i]=='?'){
			f[i][0]=max(f[i-1][0],f[i-1][1]);
			pre[i][0]=(f[i][0]==f[i-1][1]);
			f[i][1]=max(f[i-1][0]+2,f[i-1][1]+1);
			pre[i][1]=(f[i-1][1]+1==f[i][1]);
		} 
	}
	//cout<<f[n][1]<<endl;
	if(max(f[n][0],f[n][1])==f[n][0]){
		solve(n,0);
	}
	else solve(n,1);
	return 0;
}