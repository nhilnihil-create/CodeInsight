#include <cstdio>
using namespace std;
int H1,M1,H2,M2,K;
int main() {
	scanf("%d%d%d%d%d",&H1,&M1,&H2,&M2,&K);
	printf("%d\n",(H2-H1)*60+M2-M1-K);
	return 0;
} 