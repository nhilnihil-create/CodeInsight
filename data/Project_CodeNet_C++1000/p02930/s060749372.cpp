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

int ans[505][505];

int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    int mm=0;
    int curr=n-1;
    while(curr) {
        mm++;
        curr/=2;
    }

    int i,j,k;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            ans[i][j]=-1;
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(ans[i][j]>=0) continue;
            for(k=0; k<mm; k++) {
                if((i&(1<<k))!=(j&(1<<k))) {
                    ans[i][j]=k;
                }
            }
        }
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            printf("%d ", ans[i][j]+1);
        }
        printf("\n");
    }

    return 0;
}
