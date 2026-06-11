#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2e5+50;
int n;
char T[maxn];
int main() {
	scanf("%s",T),n=strlen(T);
	for(int i=0;i<n;++i) if(T[i]=='?') T[i]='D';
	puts(T);
	return 0;
}