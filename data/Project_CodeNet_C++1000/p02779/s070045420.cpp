#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n], i;
    for (i=0; i<n; i++) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    for (i=1; i<n; i++) {
        if (arr[i]==arr[i-1]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
