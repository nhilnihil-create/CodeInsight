#include <bits/stdc++.h>
#define M 1e7
using namespace std;
int main(){
	int n,i,j,b[6];
	while(cin>>n,n){
		int a[86400]={0},ans=0,c=0;
		while(n--){
			scanf("%d:%d:%d %d:%d:%d",&b[0],&b[1],&b[2],&b[3],&b[4],&b[5]);
			a[b[0]*3600+b[1]*60+b[2]]++;
			a[b[3]*3600+b[4]*60+b[5]]--;
		}
		for(i=0;i<86400;i++){
			c+=a[i];
			ans=max(ans,c);
		}
		cout<<ans<<endl;
	}
}