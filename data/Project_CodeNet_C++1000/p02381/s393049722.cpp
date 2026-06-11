#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    while (1)
    {
        int n, a[1000];
        double av=0, var=0;
        scanf("%d", &n);
        if (n==0) break;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            av+=a[i];
        }
        av/=n;
        for (int i=0; i<n; i++) var+=abs(av-a[i])*abs(av-a[i]);
        var/=n;
        printf("%.10f\n", sqrt(var));
    }
    return 0;
}

