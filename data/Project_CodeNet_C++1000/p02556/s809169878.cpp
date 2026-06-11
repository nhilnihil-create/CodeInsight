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

int main(){
    LL n;
    LL x;
    LL y;
    cin >> n;

    vector<LL> z(n);
    vector<LL> w(n);
    for(LL i=0; i<n; i++){
        cin >> x >> y;
        z[i]=x+y;
        w[i]=x-y;
    }

    sort(z.begin(), z.end());
    sort(w.begin(), w.end());
    LL ans=max(z[n-1]-z[0], w[n-1]-w[0]);

    cout << ans << endl;

    return 0;
}
