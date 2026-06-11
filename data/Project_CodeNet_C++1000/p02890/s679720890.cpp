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

    map<int,int> cnt;
    int i;
    for(i=0; i<n; i++) {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
    }

    vector<int> a;
    auto it=cnt.begin();
    for(; it!=cnt.end(); ++it) {
        a.push_back(it->second);
    }
    sort(a.rbegin(), a.rend());

    int siz=(int)a.size();
    vector<int> sa(siz+1);
    sa[0]=n;
    for(i=0; i<siz; i++) {
        sa[i+1]=sa[i]-a[i];
    }

    vector<int> ans(siz+1,INF);

    for(i=0; i<siz; i++) {
        int sq = (int)sqrt((double)sa[i]);
        int j;
        for(j=1; j<=sq; j++) {
        //for(j=1; j<=siz-i; j++) {
            int tmp=sa[i]/j;
            if(i+j<=siz) ans[i+j]=MIN(ans[i+j],tmp);
        }

        for(j=1; j<=sq; j++) {
            int tmp = sa[i]/(j+1);
            if(i+(tmp+1)<=siz) ans[i+(tmp+1)]=MIN(ans[i+(tmp+1)],j);
        }
    }

    for(i=1; i<=siz; i++) {
        ans[i]=MIN(ans[i-1],ans[i]);
    }

    for(i=1; i<=n; i++) {
        if(i>siz) {
            printf("0\n");
        }
        else {
            printf("%d\n", ans[i]);
        }
    }

    return 0;
}
