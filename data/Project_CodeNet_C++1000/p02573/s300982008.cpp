#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 2e5 + 5; 
const int INF = 0x3f3f3f3f;;
int height[MAXN], s[MAXN];
int n, m;
void setInit(){
	for(int i = 1; i <= n; i++){
		s[i] = i;
		height[i] = 0;
	}
}
int setFind(int x){
	if(x != s[x])  s[x] = setFind(s[x]);
	return s[x];
}
void setUnion(int x, int y){
	x = setFind(x);
	y = setFind(y);
	if(height[x] == height[y]){
		height[x]++;
		s[y] = x;
	}
	else{
		if(height[x] < height[y]) s[x] = y;
		else s[y] = s[x];
	}
}
int main(int argc, char *argv[]){
	scanf("%d %d", &n, &m);
	setInit();
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		setUnion(x, y);
	}
	int cnt[MAXN];
	for(int i = 1; i <= n; i++) cnt[i] = setFind(s[i]);
	int ans = -INF;
	sort(cnt + 1, cnt + n + 1);
	int num = 1;
	for(int i = 2; i <= n; i++){
		if(cnt[i] == cnt[i - 1]) num++;
		else ans = max(ans, num), num = 1;
	}	
	cout << max(ans, num);
	return 0;
}