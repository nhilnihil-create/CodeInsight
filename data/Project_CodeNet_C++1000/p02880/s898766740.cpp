#include<bits/stdc++.h>

int main(){
	bool ok = false;
	int n;
	scanf("%d", &n);
	for(int i=1; i<=9; i++){
		for(int j=1; j<=9; j++){
			if(i*j==n) ok = true;
		}
	}
	if(ok) puts("Yes");
	else puts("No");	
	return 0;
}

