#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    int n, i, j, sum, ans, tmp, up;
    scanf("%d", &n);
    int arr[n];
    for (i=0; i<n; i++) scanf("%d", &arr[i]);

    sort(arr, arr+n);
    up=arr[n-1];
    up++;
    ans=1000000000;
    for (i=arr[0]; i<up; i++) {
        sum=0;
        for (j=0; j<n; j++) {
            tmp=arr[j]-i;
            sum+=tmp*tmp;
        }
        ans=min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}
