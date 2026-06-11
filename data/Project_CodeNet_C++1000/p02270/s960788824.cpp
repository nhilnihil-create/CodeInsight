#include<cstdio>

#define MAX_N 100000
#define MAX_K 100000
#define MAX_W 10000

using namespace std;

int w[MAX_N];

int check(int n, int k, int p)
{
    int i = 0;;
    for (int j = 0; j < k; j++) {
        int sum = 0;
        while (sum + w[i] < p) {
            sum += w[i];
            i++;
            if (i >= n) return n;
        }
    }
    return i;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    long long left = 0;
    long long right = n * MAX_W;
    long long mid;
    while (left < right) {
        mid = (left + right) / 2;
        int v = check(n, k, mid);
        if (v >= n) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", right - 1);

    return 0;
}