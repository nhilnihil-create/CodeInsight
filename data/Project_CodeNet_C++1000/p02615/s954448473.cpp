# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long
  
using namespace std;
  
const int N = 1e3 + 7;
const int mod = 1e9 + 7;

int32_t main() {
    speed;
    int n;
    cin >> n;
    vector < int > a;
    for ( int i = 0; i < n; i++ ) {
        int x;
        cin >> x;
        a.push_back( x );
        a.push_back( x );
    } 
    sort( a.rbegin(), a.rend() );
    a.erase( a.begin() );
    int sum = 0;
    for ( int i = 0; i < n - 1; i++ ) {
        sum += a[i];
    }
    cout << sum;
}
