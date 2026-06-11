//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC target ("avx,avx2,tune=native")
//#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/rope>

using namespace __gnu_pbds; 
using namespace __gnu_cxx;
using namespace std;
using ll = long long;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define precision(n) fixed<<setprecision(n)

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("output.txt","w",stderr);
    #endif
}
template<typename T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;
template<typename T> using MinPriorityQueue = priority_queue <T, vector <T>, greater <T> >;
template<typename T> void done(T ans) {cout << ans << "\n"; exit(0);}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 mt(seed);

clock_t time_p=clock();
void printTime(){
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}


const int N = 2e5 + 5;

int main() {
    io();
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = 0; k < 12; k++) {
                if(((1 << k) & i) != ((1 << k) & j)) {
                    cout << (k + 1) << " ";
                    break;
                }
            }
        }
        cout << "\n";
    }
}


