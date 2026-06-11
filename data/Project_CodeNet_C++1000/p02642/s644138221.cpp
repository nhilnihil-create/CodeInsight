#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
static const int MAX_V = 1000001;
static const int MAX_N = 200001;
int arr[MAX_N];
int vals[MAX_V];

int main()
{
    int N, i, j, ans =0;
    scanf("%d",&N);
    memset(vals, 0, sizeof (vals));
    for(i = 0; i< N; i++) scanf("%d",&arr[i]);
    sort(arr, arr+ N);

    for(i = 0; i < N;i++) {
        if(vals[arr[i]] <= 1) for(j=arr[i]; j<MAX_V; j+=arr[i]) vals[j]++;
    }
    for(i = 0; i < N; i++) if(vals[arr[i]] == 1) ans++;
    printf("%d\n",ans);
    return 0;
}
