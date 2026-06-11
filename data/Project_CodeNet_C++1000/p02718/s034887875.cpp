#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 100010
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

int main()
{
    //RUN_FAST; cin.tie(nullptr);
    int n, m, i, sum, tmp, cnt;
    scanf("%d %d", &n, &m);
    int arr[n];
    sum=0;
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }
    tmp=ceil((double)sum/(double)(4*m));
    cnt=0;
    for (i=0; i<n; i++)
        if (arr[i]>=tmp) cnt++;

    if (cnt>=m) puts("Yes");
    else puts("No");
    return 0;
}
