#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
const int maxn = 1e5 + 2;

int t_in[maxn];
int main() {
	// your code goes here
	int n,id;
	while(scanf("%d",&n)==1){
		for(int i=1;i<=n; i++){
			scanf("%d",&id);
			t_in[id] = i;
		}
		for(int i=1;i<=n;i++) printf("%d ", t_in[i]);
		
	}
	return 0;
}