#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#include<iostream>
#define rep(i,a) for(i=0;i<a;i++)
#define rep2(i,a) for(i=1;i<a;i++)
using namespace std;
int main(void) 
{
	int gyoretu[102][102];
	int r,c,i,j,sum;
	cin>>r>>c;
	rep(i,r)rep(j,c) cin>>gyoretu[i][j];
	rep(i,r) {
		sum=0;
		rep(j,c) sum+=gyoretu[i][j];
		gyoretu[i][j]=sum;
	}
	rep(i,c+1) {
		sum=0;
		rep(j,r)sum+=gyoretu[j][i];
		gyoretu[j][i]=sum;
	}
	rep(i,r+1) {
		cout<<gyoretu[i][0];
		rep2(j,c+1) {
			/*if(gyoretu[i][j]==10000) printf("%6d",gyoretu[i][j]);
			else if(gyoretu[i][j]>=1000) printf("%5d",gyoretu[i][j]);
			else if(gyoretu[i][j]>=100) printf("%4d",gyoretu[i][j]);
			else if(gyoretu[i][j]>=10)printf("%3d",gyoretu[i][j]);
			else printf("%2d",gyoretu[i][j]);*/
			if(j==c+1) cout<<gyoretu[i][j];
			else cout<<" "<<gyoretu[i][j];
		}
		cout<<endl;
	}
	return 0;
}
			