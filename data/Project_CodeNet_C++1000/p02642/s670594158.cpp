#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long llint;

const int maxn = 1e6+10;
const int base = 31337;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 20;
const int off = 1 << logo;
const int treesiz = off << 1;

int n;
int niz[maxn];
bool bio[maxn];
bool bio2[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", niz+i);
		
	memset(bio, false, sizeof bio);
	sort(niz, niz+n);
	
	memset(bio2, false, sizeof bio2);
	for (int i = 1; i < n; i++) {
		if (niz[i] == niz[i - 1]) bio2[niz[i]] = true;
	}
	
	int sol = 0;
	for (int i = 0; i < n; i++) {
		if (!bio[niz[i]]) {
			sol += !bio2[niz[i]];
			for (int x = niz[i]; x < maxn; x += niz[i]) bio[x] = true;
		}
	}
	printf("%d", sol);
	return 0;
}

