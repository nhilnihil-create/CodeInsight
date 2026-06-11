#include <cstdio>

using namespace std;

int main()
{
    int d, t, s;
    scanf("%d %d %d", &d, &t, &s);
    if(d > t * s) printf("No\n");
    else printf("Yes\n");
    return 0;
}