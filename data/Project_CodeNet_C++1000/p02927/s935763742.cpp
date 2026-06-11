#include <bits/stdc++.h>
using namespace std;
int main(){
    int M,d,ans=0;
	scanf("%d%d",&M,&d);
	for(int m=1;m<=M;m++)
		for(int i=1;i<=d;i++){
			int n=i%10;
			int N=i/10%10;
			ans+=((n*N==m)&&(n>=2)&&(N>=2));
		}
	printf("%d\n",ans);
    return 0;
}