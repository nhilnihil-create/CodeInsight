#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, a[MAXN], lo[MAXN], vis[MAXN];

int main(){
	for(int i = 2; i < MAXN; i++){
		if(lo[i] != 0)continue;
		
		lo[i] = i;
		for(int j = 2 * i; j < MAXN; j += i)
			lo[j] = i;
	}
	
	scanf("%d", &n);
	
	int g = 0;
	bool ok = true;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		g = __gcd(g, a[i]);
		
		if(!ok)continue;
		
		while(a[i] > 1){
			if(vis[lo[a[i]]] != i + 1 && vis[lo[a[i]]] != 0){
				ok = false;
				break;
			}
			vis[lo[a[i]]] = i + 1;
			a[i] /= lo[a[i]];
		}
	}
	
	if(ok)printf("pairwise coprime\n");
	else if(g == 1)printf("setwise coprime\n");
	else printf("not coprime\n");
	
	return 0;
}
