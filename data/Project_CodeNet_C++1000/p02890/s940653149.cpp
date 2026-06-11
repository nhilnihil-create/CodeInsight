#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int cnt[400000];
int sum[400000];

int main(){
	int n;cin>>n;
	rep(i,n){
		int a;scanf("%d",&a);a--;
		cnt[a]++;
	}
	rep(i,n){
		if(!cnt[i])continue;
		sum[1]++;
		sum[cnt[i]+1]--;
	}
	rep(i,n)sum[i+1]+=sum[i];
	rep(i,n)sum[i+1]+=sum[i];
	for(int K=1;K<=n;K++){
		int ok=0,ng=n+1;
		while(ng-ok>1){
			int t=(ok+ng)/2;
			if(sum[t]>=t*(ll)K)ok=t;
			else ng=t;
		}
		printf("%d\n",ok);
	}
}