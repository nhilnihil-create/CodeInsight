#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<vector>
#define rep(i,a) for(int i=0;i<(a);++i)

int n,S;

int main(){
	while (scanf("%d", &n), n){
		S = n;
		std::vector<int> num(n);
		rep(i, n)num[i] = i + 1;
		int s = 0, t = 0, sum = 0;
		int ans = 0;
		for (;;){
			while (t < n && sum < S){
				sum += num[t++];
			}
			if (sum < S) break;
			if(sum == S)ans++;
			//res = std::min(res, t - s);
			sum -= num[s++];
		}
		printf("%d\n", ans-1);
	}
	return 0;
}