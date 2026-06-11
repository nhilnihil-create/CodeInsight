#include<bits/stdc++.h>
int A,V,B,W,T;
int main(){
	scanf("%d%d%d%d%d",&A,&V,&B,&W,&T);
	puts(V>W && abs(A-B)<=1ll*T*(V-W)?"YES":"NO");
}