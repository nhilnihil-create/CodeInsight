#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int h, w, a, b;

int main(){
	scanf("%d%d%d%d", &h, &w, &a, &b);
	for(int i = 0;i < h;i++){
		for(int j = 0;j < w;j++){
			printf("%d", (i < b) ^ (j < a));
		}
		printf("\n");
	}

	return 0;
}