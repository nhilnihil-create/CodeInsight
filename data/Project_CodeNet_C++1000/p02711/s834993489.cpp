#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, fact = 1;

    scanf("%d", &n);

    int t = n;

    while(t) {
        t = t / 10;
        fact = fact * 10;
    }

    while(fact > 1) {
        fact = fact / 10;
        if(n / fact == 7) {
            printf("Yes\n");
            return 0;
        }
        n = n % fact;
    }
    printf("No\n");

    return 0;
}