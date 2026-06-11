#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
using namespace std;

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    int curr=1;
    int i;
    for(i=0; i<20; i++) {
        if(n==curr) {
            printf("No\n"); return 0;
        }
        if(curr*2>n) break;
        curr*=2;
    }
    printf("Yes\n");

    printf("%d %d\n", 2+n, 1+n);
    int k=(n-1)/2;
    for(i=1; i<=k; i++) {
        printf("%d %d\n", 1, 2*i);
        printf("%d %d\n", 1, 2*i+1);
        printf("%d %d\n", 2*i,   n+2*i+1);
        printf("%d %d\n", 2*i+1, n+2*i);
    }
    if((n-1)%2) {
        printf("%d %d\n", curr, n);
        printf("%d %d\n", n^curr^1, 2*n);
    }

    return 0;
}

