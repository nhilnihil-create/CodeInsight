#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,W,H;
	scanf("%d%d%d" ,&W,&H,&N);
	if(H<W){
		printf("%d",(N+W-1)/W);
		
		
	}else{
		printf("%d",(N+H-1)/H);
		
	}
	

}


