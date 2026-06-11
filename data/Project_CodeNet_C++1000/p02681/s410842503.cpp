#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10;
char s[N + 1];
char t[N + 2];

int main() 
{
	scanf("%s%s", s, t);
	int n = strlen(s);
	t[n] = 0;
	if (!strcmp(s, t)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
