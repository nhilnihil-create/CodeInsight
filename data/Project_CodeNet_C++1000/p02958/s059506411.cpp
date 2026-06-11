#include<bits/stdc++.h>

int main(){
	int n;
	scanf("%d", &n);
	int p[n];
	for(int i=0; i<n; i++) scanf("%d", &p[i]);

	int cnt = 0;
	for(int i=0; i<n; i++){
		if(p[i]!=i+1) cnt++;
	}

	if(cnt<=2) puts("YES");
	else puts("NO");
	return 0;
}

