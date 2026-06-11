#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
const int MAX=1e9+7;
int n,x1,x2,x,ans,ansa[100010],ansb[100010],Min,a[100010],tota,b[100010],totb,tot,sum,suma,sumb,Max;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d",&x1,&x2);
	Max=max(x1,x2);
	Min=min(x1,x2);
	for(int i=3;i<=n;i++){
		scanf("%d",&x);
		if(x<Min){
			if(Min>0){
				tota++;
				a[tota]=Min;
			}
			else{
				totb++;
				b[totb]=Min;
			}
			Min=x;
		}
		else if(x>Max){
			if(Max>0){
				tota++;
				a[tota]=Max;
			}
			else{
				totb++;
				b[totb]=Max;
			}
			Max=x;
		}
		else{
			if(x>0){
				tota++;
				a[tota]=x;
			}
			else{
				totb++;
				b[totb]=x;
			}
		}
	}
	suma=Max;
	sumb=Min;
	for(int i=1;i<=tota;i++){
		sum++;
		ansa[sum]=sumb;
		ansb[sum]=a[i];
		sumb-=a[i];
	}
	for(int i=1;i<=totb;i++){
		sum++;
		ansa[sum]=suma;
		ansb[sum]=b[i];
		suma-=b[i];
	}
	sum++;
	ansa[sum]=suma;
	ansb[sum]=sumb;
	ans=suma-sumb;
	printf("%d\n",ans);
	for(int i=1;i<=sum;i++){
		printf("%d %d\n",ansa[i],ansb[i]);
	}
	return 0;
}