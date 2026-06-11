#include <bits/stdc++.h>
#define X first
#define Y second
 
using namespace std;
typedef long long llint;
 
const int maxn = 1e6+10;
const int maxm = 1e6+10;
const int base = 31337;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 20;
const int off = 1 << logo;
const int treesiz = off << 1;

int n;
int a[maxn];
int bio[maxm + 20];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a+i);

	for (int i = 0; i < n; i++) bio[a[i]]++;

	bool flag = true;
	for (int i = 2; i < maxm; i++) {
		int cnt = 0;
		for (int j = i; j < maxm; j += i)
			cnt += bio[j];
		if (cnt > 1) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("pairwise coprime");
		return 0;
	}

	flag = true;
	for (int i = 2; i < maxm; i++) {
		int cnt = 0;
		for (int j = i; j < maxm; j += i) 
			cnt += bio[j];
		if (cnt == n) {
			flag = false;
			break;
		}
	}

	if (flag) {
		printf("setwise coprime");
	} else printf("not coprime");
	return 0;
}