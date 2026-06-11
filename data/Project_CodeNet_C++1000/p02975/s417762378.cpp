#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, a[100005];
map<int, int> M;

int s[100005];

int main(){
	scanf("%d", &n);
	
	int distinct = 0;
	
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(!M.count(a[i])){
			M[a[i]] = 1;
			distinct++;
		}else{
			M[a[i]]++;
		}
	}
	
	if(distinct > 3){
		printf("No\n");
		return 0;
	}else if(distinct == 3){
		int xx = 0;
		for(auto it: M){
			xx ^= it.first;
			if(it.second * 3 != n){
				printf("No\n");
				return 0;
			}
		}
		if(xx == 0){
			printf("Yes\n");
			return 0;
		}else{
			printf("No\n");
			return 0;
		}
	}else{
		int target;
		if(distinct == 1){
			target = n;
		}else{
			if(n % 3){
				printf("No\n");
				return 0;
			}
			target = n / 3;
		}
		if(!M.count(0) || M[0] != target){
			printf("No\n");
			return 0;
		}
	}
	
	printf("Yes\n");
	return 0;
}