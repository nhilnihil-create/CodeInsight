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

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt","w", stdout);
    fio;
    int n, k, c;
    cin >> n >> k >> c;
    string st;
    cin >> st;
    //lazy, eager
    vector<int> la(k), ea(k);
    int ind = 0;
    for (int i = 0; i < n && ind < k; ++i) {
        if (st[i] == 'o') {
            ea[ind] = i;
            ind++;
            i+=c;
        }
    }
    ind = k-1;
    for (int i = n-1; i>=0 && ind >= 0; --i) {
        if (st[i] == 'o') {
            la[ind] = i;
            ind--;
            i-=c;
        }
    }
    //nxt[i] gives the next 'o' index after i
    vector<int> nxt(n);
    int prev = n+1;
    for (int i = n-1; i>=0; --i) {
        nxt[i] = prev;
        if (st[i] == 'o')
            prev = i;
    }
    int ce = 0;//current eager index
    for (int i = 0; i < n; ++i) {
        if (ce >= k)
            break;
        if (st[i] == 'x')
            continue;
        while (i < ea[ce]) {
            i++;
        }
        if (i == ea[ce]) {
            if (nxt[i] > la[ce]) {
                ce++;
                cout << i+1 << '\n';
            }
        } else if (i > la[ce]){
            ce++;
            i--;
        } 
    }

    return 0;
}
/* BEFORE submitting, check for:
 *  1. Integer overflow
 *  2. Float/Double precision errors
 *  3. Array index out of bounds
 *  4. Edge cases.(n=1, n=max, etc.)
 *  5. Time complexity. No TLEs
 */

