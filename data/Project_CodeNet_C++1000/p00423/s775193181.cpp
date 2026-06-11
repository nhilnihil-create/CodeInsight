#include<cstdio>
main(){
	int n;
	while(scanf("%d",&n),n){
		int a,b,c = 0,d = 0;
		while(n--){
			scanf("%d%d",&a,&b);
			c+=a>b?a+b:a==b?a:0;
			d+=b>a?a+b:a==b?b:0;
		}
		printf("%d %d\n",c,d);
	}
}