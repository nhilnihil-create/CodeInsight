#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){

	int n, x;
	scanf("%d %d", &n, &x);
	int cont = 1, bounce = 0;

	rep(i,n){

		int l;
		scanf("%d", &l);
		
		if (bounce + l <= x){
			bounce += l;
			cont++;
		}else
			break;	
	}

	printf("%d\n", cont);
	return 0;
}
