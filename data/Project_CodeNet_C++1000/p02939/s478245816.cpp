#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[200002];
int f[200001][7];
int main(){
	int n;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=0;i<=n;i++)
		for(int j=0;j<6;j++)
			f[i][j]=i==j+1?1:-2e9;
	for(int i=1;i<=n;i++)
		for(int j=0;j<6;j++){
		//	printf("%d %d %d\n",i,j,f[i][j]);
			if(i-j<1)continue;
			for(int k=0;k<6;k++){
				if(i+k+1>n)continue;
				if(k==j){
					int ok=1;
					for(int w=0;w<=k;w++)
						if(s[i+w+1]!=s[i-j+w])
							ok=0;
					if(ok)continue;
				}
				f[i+k+1][k]=max(f[i+k+1][k],f[i][j]+1);
			}
		}
	int ans=0;
	for(int i=0;i<6;i++)
		ans=max(ans,f[n][i]);
	printf("%d\n",ans);
}
