#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define MAX_N 50
#define MAX 1e9 + 1
int d[MAX_N][MAX_N];
int n;

void floyd(int n) {
	for(int k=0; k<=n; k++) {
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=n; j++) {
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
				
			}
		}

	}
}

int main() {
	int a,b,c;
	int sum;
	int s;
	int max_s;
	while(scanf("%d",&n)&&n!=0) {
		sum = MAX;
		max_s = 0;
		for(int i=0; i<10; i++) {
			for(int j=0; j<10; j++) {
				d[i][j] = MAX;
			}
		}
		for(int i=0; i<10; i++) d[i][i] = 0;

		for(int i=0; i<n; i++) {
			scanf("%d%d%d",&a,&b,&c);
			max_s = max(max_s,max(a,b));
			d[a][b] = d[b][a] = c;
		}
		
		floyd(max_s);
		for(int i=0;i<=max_s;i++){
			int x =0;
			for(int j=0;j<=max_s;j++){
				x+=d[i][j];
			}
			if(sum>x){
				sum = x;
				s = i;
			} 
		}
		printf("%d %d\n",s,sum);
	}
}