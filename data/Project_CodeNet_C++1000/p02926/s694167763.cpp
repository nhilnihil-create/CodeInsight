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
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;
using namespace std;


 
 
int main(int argc, char* argv[])
{
    int n;
    scanf("%d", &n);

    vector<pair<double, pair<int,int> > > z;
    int i,j;
    for(i=0; i<n; i++) {
        int x,y;
        scanf("%d%d", &x, &y);
        double t=0;
        if(x!=0 || y!=0) {
            t = atan2((double)y, (double)x);
        }
        z.push_back(make_pair(t, make_pair(x,y)));
    }
    sort(z.begin(), z.end());

    int k;
    double sx0=0, sy0=0;
    for(k=0; k<n; k++) {
        sx0+=z[k].second.first;
        sy0+=z[k].second.second;
    }

    double maxval=0;
    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            double sx=0, sy=0;
            for(k=0; k<n; k++) {
                if(k>=i && k<=j) {
                    sx+=z[k].second.first;
                    sy+=z[k].second.second;
                }
            }
            double val=(sx*sx+sy*sy);
            maxval=MAX(maxval,val);

            sx=sx0-sx; sy=sy0-sy;
            val=(sx*sx+sy*sy);
            maxval=MAX(maxval,val);
        }
    }
    maxval=sqrt(maxval);
    printf("%.10lf\n", maxval);

    return 0;
}

