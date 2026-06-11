#include <stdio.h>
#include <string.h>

int main(){
long long int a, b, v, w, t;
scanf("%lld %lld", &a, &v);
scanf("%lld %lld", &b, &w);
scanf("%lld", &t);
if(a < b){
if(((v * t) + a) >= ((w * t) + b)){
		printf("YES\n");
}else{
		printf("NO\n");
}
}else if(a > b){
	if(((v * t) - a) >= ((w * t) - b)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}else{
	printf("YES\n");
}
return 0;
}