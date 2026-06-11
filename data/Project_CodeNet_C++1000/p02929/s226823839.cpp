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
const long long Mod=1e9+7;
int n;
long long ans=1,tot;
char s[200020];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n*2;i++){
		if((s[i]=='B')^(i&1)) tot++;
		else{
			if(!tot){
				printf("0\n");
				return 0;
			}
			ans*=tot;
			ans%=Mod;
			tot--;
		}
	}
	if(tot){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		ans=ans*i%Mod;
	printf("%lld\n",ans);
	return 0;
}