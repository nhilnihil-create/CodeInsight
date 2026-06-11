#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <memory>
#include <functional>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int ans=987654;
		int cnt[2]={0};
		int	dp[11][11];
		int memo[11]={};
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++){
				dp[i][j]=987654;
			}
		}
		if(n==0)break;
		int a,b,c;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			dp[a][b]=c;
			dp[b][a]=c;
			memo[a]++;
			memo[b]++;
		}
		int N=0;
		for(int i=0;i<10;i++){
			if(memo[i]>0){
				N++;
			}
		}
		for(int m=0;m<N;m++){
		for(int k=0;k<N;k++){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		cnt[1]=0;
		for(int i=0;i<N;i++){
			cnt[1]+=dp[m][i];
		}
		cnt[1]-=dp[m][m];
		if(ans>cnt[1]){
			cnt[2]=m;
			ans=cnt[1];
		}
		}
		cout<<cnt[2]<<" "<<ans<<endl;
	}
	return 0;
}