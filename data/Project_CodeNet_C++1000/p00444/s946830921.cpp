#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<functional>
#include<cstring>
using namespace std;
int main() {
	int n;
	while(scanf("%d",&n),n){
		n = 1000 - n;
		int cnt = 0;
		if(500 <= n){
			n -= 500;
			cnt++;
		}
		if(100 <= n){
			cnt += n / 100;
			n %= 100;
		}
		if(50 <= n){
			cnt += n / 50;
			n %= 50;
		}
		if(10 <= n){
			cnt += n / 10;
			n %= 10;
		}
		if(5 <= n){
			cnt += n / 5;
			n %= 5;
		}
		cnt += n;
		printf("%d\n",cnt);
	}
    return 0;
}