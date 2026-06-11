#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int a[223456];
int n,k;
bool check(int t){
	ll sum=0;
	for(int i=1;i<=n;i++){
		sum+=(int)ceil(a[i]*1.0/t)-1;
	}
	if(sum>k)return false;
	return true;
}
int main(){
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int l=1,r=1e9;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
} 
