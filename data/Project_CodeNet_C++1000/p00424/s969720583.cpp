#include <iostream>
#include <cstdio>
using namespace std;

char a[10001], b[10001], data[100001];

void solve(int n, int m) {
  bool isHit;
  for(int i = 0; i < m; ++i) {
	isHit = 0;
	for(int j = 0; j < n; ++j) {
	  if(data[i] == a[j]) {
		printf("%c", b[j]);
		isHit = 1;
		break;
	  }
	}
	if(!isHit) {
	  printf("%c", data[i]);
	}
  }
  printf("\n");
}

int main() {
  int n, m;
  while(scanf("%d", &n) && n) {
	for(int i = 0; i < n; ++i) {
	  scanf(" %c %c", &a[i], &b[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
	  scanf(" %c", &data[i]);
	}
	solve(n, m);
  }
  return 0;
}