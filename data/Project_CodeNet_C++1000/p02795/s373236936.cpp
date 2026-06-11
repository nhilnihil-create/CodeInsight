#include<bits/stdc++.h>
int main(){
	int H,W,N;
	scanf("%d%d%d",&H,&W,&N);
	if(H<W)std::swap(H,W);
	printf("%d\n",(N+H-1)/H);
}