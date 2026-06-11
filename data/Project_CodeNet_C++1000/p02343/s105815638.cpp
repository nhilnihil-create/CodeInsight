#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int p[10000];
int h[10000];
int n;
int q;
 queue<int>z;
int pa(int x){
	int zz;
	if (p[x] == x){
		for (; z.empty() == 0;){
			zz = z.front();
			p[zz] = x;
			z.pop();
		}
		return x;
	}
	else{
		z.push(x);
		return pa(p[x]);
	}
}
void un(int x, int y){
	int max;
	if (h[x] < h[y]){
		p[x] = y;
	}
	else if(h[x]>h[y]){
		p[y] = x;
	}
	else{
		p[y] = x;
		h[x]++;
	}
}
void ju(int x, int y){
	if (x == y)printf("1\n");
	else printf("0\n");
}
int main(void){
	scanf("%d %d", &n,&q);
	int w, x, y;
	int a, b;
	for (int i = 0; i < 10000; i++){
		h[i] = 1;
		p[i] = i;
	}
	for (int qq; qq < q; qq++){
		scanf("%d %d %d", &w, &x, &y);
		a = pa(x);
		b = pa(y);
		if (w == 0)un(a, b);
		else ju(a, b);
	}

		return 0;
	}