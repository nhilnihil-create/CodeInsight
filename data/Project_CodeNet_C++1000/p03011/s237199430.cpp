#include<cstdio>
#include<algorithm>
using namespace std;

int main(void) {
	int t[3];
	for (int i = 0; i < 3; i++) {
		scanf("%d", &t[i]);
	}
	sort(t, t + 3);
	printf("%d", t[0] + t[1]);

	return 0;
}
