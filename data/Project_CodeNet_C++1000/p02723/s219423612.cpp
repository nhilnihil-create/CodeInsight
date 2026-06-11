# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
    char a[100];
    scanf("%s",a);
    if (a[2]==a[3]&&a[4]==a[5]) printf("Yes\n");
    else printf("No\n");

    return 0;
}