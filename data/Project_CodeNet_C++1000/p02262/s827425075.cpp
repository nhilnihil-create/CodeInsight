#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e6 + 5;

int a[maxn];
int g[maxn];

vector<int >G;
int cnt = 0;

int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n; i = i*3+1)G.push_back(i);
	int sk = G.size();
	printf("%d\n",sk);
	for(int i = G.size()-1;i >= 0; i--){
		printf("%d",G[i]);
		if(i)printf(" ");
	}
	for(int k = G.size()-1;k >= 0; k--){
		int g = G[k];
		for(int i = g;i <= n; i++){
			int v = a[i];
			int j = i - g;
			while(j >= 1 && a[j] > v){
				a[j+g] = a[j];
				j -= g;
				cnt++;
			}
			a[j+g] = v;
		}
	}
	printf("\n%d\n",cnt);
	for(int i = 1;i <= n; i++)printf("%d\n",a[i]);
}