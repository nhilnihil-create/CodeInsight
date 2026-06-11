#include<bits/stdc++.h>

#define int long long 
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lbound lower_bound 
#define ubound upper_bound
#define pqueue priority_queue
#define umap unordered_map
#define uset unordered_set
#define len(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using namespace std ;

using vi   = vector<int> ;
using vvi  = vector<vi> ;
using pii  = pair<int,int> ;
using vpii = vector<pii>  ;
using mii  = map<int, int>;
using umii = umap<int, int>; 

template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

int32_t main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("D:/Coding/in.txt", "r", stdin);
    freopen("D:/Coding/out.txt", "w", stdout);
#endif
    int n ;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
         cin >> a[i];
    sort(all(a));
    int mid = n / 2;
    if(a[mid] == a[mid - 1]){
         cout << 0 ; 
    } else{
         cout << a[mid] - a[mid - 1];
    }


#ifndef ONLINE_JUDGE  
    cerr << "\n\nTime elapsed: " << 1.0 * clock() /CLOCKS_PER_SEC<< " s.\n";
#endif
    return 0;
}