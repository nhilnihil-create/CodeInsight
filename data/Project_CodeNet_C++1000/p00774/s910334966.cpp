#include <bits/stdc++.h>
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,N,n) for(int i=N;i>=n;i++)
#define CH(n,a,b) (a)<=(n)&&(n)<(b)
#define p(s) cout<<(s)<<endl
typedef long long ll;
using namespace std;

int main() {
	int H;
	while(cin>>H,H){
		int field[12][5];
		bool flag[12][5];
		int ans=0;
		REP(j,0,5) field[0][j]=-1;
		REP(i,1,H+1) REP(j,0,5) cin>>field[i][j];
		bool ok=true;
		while(ok){
			REP(i,0,12) REP(j,0,5) flag[i][j]=false;
			ok=false;
			REP(i,1,H+1){
				int prev=0,tmp=1;
				REP(j,0,5){
					if(field[i][j]==-1){
						prev=-1;
						tmp=1;
						continue;
					}
					if(field[i][j]==prev){
						tmp++;
						if(j==4&&tmp>2){
							ok=true;
							ans+=prev*tmp;
							for(int k=4;k>j-tmp;k--) flag[i][k]=true;
							break;
						}
					}
					else{
						if(tmp<3) {
							prev=field[i][j];
							tmp=1;
						}
						else{
							ok=true;
							ans+=prev*tmp;
							for(int k=j-1;k>=j-tmp;k--) flag[i][k]=true;
							break;
						}
					}
				}
			}
			REP(i,1,H+1){
				REP(j,0,5){
					if(flag[i][j]) {
						for(int k=i;(k>0&&field[k][j]!=-1);k--)field[k][j]=field[k-1][j];
					}
				}
			}
		}
		p(ans);
	}
	return 0;
}