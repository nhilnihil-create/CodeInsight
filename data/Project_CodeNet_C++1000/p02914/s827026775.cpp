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
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#include <bitset>
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

    vector<ll> a(n);
    int i;
    ll sum=0;    // 全てのa[i]のxor
    for(i=0; i<n; i++) {
        scanf("%lld", &a[i]);
        sum^=a[i];
    }

    for(i=0; i<n; i++) {
        a[i] &= ~sum;    // 全てのa[i]のxorが0であるbitだけを見る形の a[i] を用意
    }

    int curr=0;
    int k;
    for(k=59; k>=0; k--) {
        for(i=curr; i<n; i++) {
            if(a[i] & ((ll)1<<k)) break;      // このbitが立っているa[i]を見つける
        }
        if(i<n) {
            swap(a[curr], a[i]);              // swapして掃き出し
            for(i=0; i<n; i++) {
                if(i!=curr && (a[i] & ((ll)1<<k))) {
                    a[i]^=a[curr];
                }
            }
            curr++;
        }
    }

    ll ans=0;
    for(i=0; i<n; i++) {
        ans ^= a[i];
    }
    ans *= 2;

    ans += sum;      // 全てのa[i]のxorが1であるbitはそのまま答に加算

    printf("%lld\n", ans);

    return 0;
}
