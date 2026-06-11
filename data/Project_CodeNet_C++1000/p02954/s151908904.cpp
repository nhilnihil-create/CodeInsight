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
    string s;
    cin >> s;
    int n = s.size();
    vector < int > l, r, ans(n);
    for ( int i = 0; i < n; i++ ) {
        if ( s[i] == 'L' ) {
            l.push_back( i );
        }
        else {
            r.push_back( i );
        }
    } 
    for ( int i = 0; i < n; i++ ) {
        if ( s[i] == 'R' ) {
            int ind = upper_bound( l.begin(), l.end(), i ) - l.begin();
            int j = l[ind];
            int dist = j - i;
            if ( dist & 1 ) {
                ans[j - 1]++;
            }
            else {
                ans[j]++;
            }
        }
        else {
            int ind = lower_bound( r.begin(), r.end(), i ) - r.begin();
            int j = r[ind - 1];
            int dist = j - i;
            if ( dist & 1 ) {
                ans[j + 1]++;
            }
            else {
                ans[j]++;
            }
        }
    }
    for ( auto i: ans ) {
        cout << i << ' ';
    }
}
