/********IN THE NAME OF ALLAH**********/
/*THE MOST GRACIOUS, THE MOST MERCIFUL*/

#include <bits/stdc++.h>
using namespace std;


#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define ull unsigned long long
#define pqueue priority_queue
#define uset unordered_set
#define umset unordered_multiset
#define bsearch binary_search
#define gcd __gcd
#define clz __builtin_clz
#define ctz __builtin_ctz
#define popcount __builtin_popcount
#define parity __builtin_parity
#define mp make_pair
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define in insert
#define out erase
#define low lower_bound
#define up upper_bound
#define endl '\n'
#define N 10000000
#define INF 1000000007

int a[N];
int main() {
    int n;
    cin >> n;
    int c = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 1; i <= n; i++) {
        if(i % 2 != 0 && a[i - 1] % 2 != 0)
            c++;
    }
    cout << c << endl;
}