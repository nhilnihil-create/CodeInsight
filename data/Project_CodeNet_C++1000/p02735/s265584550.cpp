#include<bits/stdc++.h>
using namespace std;
int _data[105][105];
int f[105][105];
signed main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;++i)
		for(register int j=1;j<=m;++j){
			char c;
			while((c=getchar())!='.'&&c!='#');
			_data[i][j]=(c=='#');
		}
	f[1][1]=_data[1][1];
	for(register int i=2;i<=n;i++){
		f[i][1]=f[i-1][1]+(_data[i][1]&&!_data[i-1][1]);
	}
	for(register int j=2;j<=m;j++){
		f[1][j]=f[1][j-1]+(_data[1][j]&&!_data[1][j-1]);
	}
	for(register int i=2;i<=n;i++)
		for(register int j=2;j<=m;j++){
			f[i][j]=min(f[i-1][j]+(_data[i][j]&&!_data[i-1][j]),f[i][j-1]+(_data[i][j]&&!_data[i][j-1]));
		}
	printf("%d\n",f[n][m]);
	return 0;
}