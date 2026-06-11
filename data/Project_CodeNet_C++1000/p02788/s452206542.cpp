#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

bool cmp(pair<LL,LL> &x, pair<LL,LL> &y)
{
    return x.first < y.first;
}

int main(){
    LL n;
    LL d;
    LL a;
    cin >> n >> d >> a;
    vector<pair<LL,LL>> xh(n);
    vector<LL> x(n);
    vector<LL> h(n);
    vector<LL> endp;
    vector<LL> endv;
    for(LL i=0; i<n; i++){
        cin >> xh[i].first >> xh[i].second;
        xh[i].first--;
    }
    sort(xh.begin(), xh.end(), cmp);
    for(LL i=0; i<n; i++){
        x[i]=xh[i].first;
        h[i]=xh[i].second;
    }
    LL sum=0;
    LL idx=0;
    LL ans=0;
    for(LL i=0; i<n; i++){
        auto itr=lower_bound(endp.begin(), endp.end(), x[i]);
        LL dist=distance(endp.begin(), itr);
        //cout << "dist " << dist << endl;
        for(LL i=idx; i<dist; i++){
            sum-=endv[i];
        }
        //cout << i << " " << sum << endl;
        idx=max(idx, dist);
        if(h[i]>sum){
            LL tmp;
            if((h[i]-sum)%a==0){
                tmp=(h[i]-sum)/a;
            }else{
                tmp=(h[i]-sum)/a+1;
            }
            //cout << tmp << endl;
            sum=sum+tmp*a;
            //cout << "endp " << x[i]+2*d << endl;
            endp.push_back(x[i]+2*d);
            endv.push_back(tmp*a);
            ans+=tmp;
        }
    }

    cout << ans << endl;

    return 0;
}
