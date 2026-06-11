#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char s[N];int f[N][3];
signed main(){
	cin>>(s+1);
	int n=strlen(s+1);
	if(n==1) return puts("1"),0;
	f[1][1]=1;
	f[2][1]=(s[1]==s[2])?0:2;
	f[2][2]=1;
	for(int i=3;i<=n;++i){
		if(s[i]!=s[i-1]) f[i][1]=max(f[i-1][1],f[i-1][2])+1;
		else f[i][1]=f[i-1][2]+1;
		string tmp1="",tmp2="";
		tmp1+=s[i-1];tmp1+=s[i];
		tmp2+=s[i-3];tmp2+=s[i-2];
		if(tmp1==tmp2) f[i][2]=max(f[i-2][1],f[i-2][2])+1;
		else f[i][2]=f[i-2][1]+1;
//		cout<<f[i][1]<<" "<<f[i][2]<<endl;
	}
	cout<<max(f[n][1],f[n][2]);
	return 0;
}