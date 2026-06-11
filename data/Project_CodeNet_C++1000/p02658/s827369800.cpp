#include <bits/stdc++.h>
#define INF 1000000000000000000LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll a[100005];

int main(void){
	scanf("%d",&n);
	bool flag=false;
	bool zero=false;
	ll res=1;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(res>0 && (INF/res)<a[i]){
			flag=true;
		}
		if(a[i]==0LL){
			zero=true;
		}
		res=res*a[i];
	}
	if(flag && !zero){
		printf("-1\n");
	}else{
		printf("%lld\n",res);
	}
	return 0;
}
