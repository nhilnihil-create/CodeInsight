#include <cstdio>
using namespace std;

int main() {
    char a[10];
    int N;
    scanf("%d %s", &N, a);
    if (N >= 3200) printf("%s\n", a);
    else printf("red\n");
    return 0;
}
