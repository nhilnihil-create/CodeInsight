#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;
int a[200005], b[200005];

long long ans = 0;

queue<int> Q;
bool in_queue[200005];

int nx(int id){
	return (id + 1) % n;
}
int pv(int id){
	return (id + n - 1) % n;
}

void check(int i){
	if(!in_queue[i] && b[i] >= b[nx(i)] + b[pv(i)]){
		in_queue[i] = true;
		Q.push(i);
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
		if(b[i] < a[i]){
			printf("-1\n");
			return 0;
		}
	}
	
	for(int i = 0; i < n; i++){
		check(i);
	}
	while(!Q.empty()){
		int i = Q.front();
		Q.pop();
		in_queue[i] = false;
		int gap = b[nx(i)] + b[pv(i)];
		int op = (b[i] - a[i]) / gap;
		ans += op;
		b[i] -= op * gap;
		check(nx(i));
		check(pv(i));
	}
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
}