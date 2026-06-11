#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int fr[N+100],bac[N+100],pre[N+100];
char str[N+100];

int main()
{
	int n,k,c;
	scanf("%d%d%d",&n,&k,&c);
	scanf("%s",str+1);
	int total = 0;
	for(int i=1;i<=n;){
		if(str[i]=='o'){
			fr[i] = ++total;
			i += c+1;
		}
		else{
			i++;
		}
	}
	total = 0;
	for(int i=n;i>0;){
		if(str[i]=='o'){
			bac[i] = ++total;
			i -= (c+1);
		}
		else{
			i--;
		}
	}
	for(int i=n;i>0;i--){
		if(bac[i]==0){
			bac[i] = bac[i+1];
		}
	}
	for(int i=1;i<=n;i++){
		if(fr[i]==0){
			pre[i] = pre[i-1];
		}
		else{
			pre[i] = i;
		}
	}
	//for(int i=1;i<=n;i++){
		//printf("%d %d\n",fr[i],bac[i]);
	//}
	for(int i=1;i<=n;i++){
		if(str[i]=='x'){
			continue;
		}
		int bef = pre[i-1];
		int aft;
		if(fr[bef]){
			aft = max(i+1,bef+c+1);
		}
		else{
			aft = i+1;
		}
		if(fr[bef]+bac[aft]<k){
			printf("%d\n",i);
		}
	}
}
