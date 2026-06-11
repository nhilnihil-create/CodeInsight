/*
 #pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
*/
#pragma GCC optimize("O3")
#pragma GCC target ("sse4")

#define NDEBUG
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <climits>
#include <list>
#include <functional>
#include <numeric>

//find out the use of the below
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define PI acos(-1)
bool cmp(const pii& a, const pii& b){
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt","w", stdout);
    fio;
    int n;
    cin >> n;
    vector<pii> en(n, mp(0,0));
    for (int i = 0; i < n; ++i){
        cin >> en[i].x >> en[i].y;
    }
    sort(en.begin(), en.end(), cmp);
    long long ansq = 0;
    for (int i = 0; i < n; ++i){
        long long tx = en[i].x, ty = en[i].y;
        for (int tj = i+1; tj <= i+n-1; ++tj){
            int j = tj%n;
            ansq = max(ansq, tx*tx + ty*ty);
            tx += en[j].x;
            ty += en[j].y;
        }
        ansq = max(ansq, tx*tx + ty*ty);
    }
    cout << setprecision(12) << sqrt((long double)ansq);
    return 0;
} /* BEFORE submitting, check for:
 *  1. Integer overflow
 *  2. Float/Double precision errors
 *  3. Array index out of bounds
 *  4. Edge cases.(n=1, n=max, etc.)
 *  5. Time complexity. No TLEs
 */

