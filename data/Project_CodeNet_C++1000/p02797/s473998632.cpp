#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,s;
	scanf("%d %d %d",&n,&k,&s);
	int inf = 1e9;
	if (s == inf) inf--;
	for (int i = 1; i <= k; i++) printf("%d%s" , s , i == n ? "\n" : " ");
	for (int i = k + 1; i <= n; i++) printf("%d%s" , inf , i == n ? "\n" : " ");
} 