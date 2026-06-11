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

    const double PI=acos((double)-1);
    const double eps=1e-14;
    vector<pair<double, pair<int,int> > > z(n);
    int i,j;
    for(i=0; i<n; i++) {
        int x,y;
        scanf("%d%d", &x, &y);
        double t=0;
        if(x!=0 || y!=0) {
            t=atan2((double)y,(double)x);
            if(t<-PI+eps) t+=2*PI;
        }
        z[i]=make_pair(t, make_pair(x,y));
    }
    sort(z.begin(), z.end());

    vector<double> sx(n+1,0), sy(n+1,0);
    for(i=0; i<n; i++) {
        sx[i+1]=sx[i]+z[i].second.first;
        sy[i+1]=sy[i]+z[i].second.second;
    }

    vector<double> args;
    args.push_back(-PI-eps*2);
    for(i=0; i<n; i++) {
        double tmp=z[i].first;
        args.push_back(tmp);
        args.push_back(tmp>=0? tmp-PI: tmp+PI);
    }
    args.push_back(PI+eps*2);
    
    double ans=0;
    for(i=0; i<(int)args.size(); i++) {
        j=lower_bound(z.begin(),z.end(),make_pair(args[i]-eps, make_pair(0,0)))-z.begin();
        int k=lower_bound(z.begin(),z.end(),make_pair(args[i]+PI-eps, make_pair(0,0)))-z.begin();
        double sumx=sx[k]-sx[j];
        double sumy=sy[k]-sy[j];
        double ans0=sumx*sumx+sumy*sumy;
        ans=MAX(ans,ans0);

        sumx=sx[n]-sumx;
        sumy=sy[n]-sumy;
        ans0=sumx*sumx+sumy*sumy;
        ans=MAX(ans,ans0);
    }
    printf("%.16lf\n", sqrt(ans));

    return 0;
}
