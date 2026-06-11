#include <iostream>
#include <vector>
//#include <string>
#include <algorithm>
//#include <math.h>
#include <queue>
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
//#define MAX 200100
//#define NIL -1

bool cmp(const pair<LL, LL> &x, const pair<LL, LL> &y)
{
    if(x.first==y.first){
        return x.second > y.second;
    }else{
        return x.first < y.first;
    }
}

int main() {
    int n;
    int m;
    vector<pair<LL, LL>> ab;
    LL tmp_a;
    LL tmp_b;
    vector<LL> a;
    vector<LL> b;
    priority_queue<LL> PQ;
    LL ans=0;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> tmp_a >> tmp_b;
        ab.push_back(make_pair(tmp_a, tmp_b));
    }
    sort(ab.begin(),ab.end(),cmp);

    for(int i=0; i<n; i++){
        a.push_back(ab[i].first);
        b.push_back(ab[i].second);
    }

    for(int i=1; i<=m; i++){
        auto pos_start=lower_bound(a.begin(), a.end(), i);
        auto pos_end=lower_bound(a.begin(), a.end(), i+1);
        int idx_start=distance(a.begin(), pos_start);
        int idx_end=distance(a.begin(), pos_end);
        for(int i=idx_start; i<idx_end; i++){
            PQ.push(b[i]);
        }
        if(!PQ.empty()){
            ans+=PQ.top();
            PQ.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
