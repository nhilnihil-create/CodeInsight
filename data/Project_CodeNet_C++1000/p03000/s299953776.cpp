#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define rev(v) reverse(v.begin(), v.end());
#define mx(v) max_element(v.begin(), v.end());
#define mn(v) min_element(v.begin(), v.end()); 
#define fastio() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
//ffs = lsb, clz = l0's, ctz = r0's, popcount = 1's 
 //++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++
using namespace std;
 //++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
	fastio();
    int n, x; cin >> n >> x;
    vector<int> v;
    v.push_back(0);
    int s = 0, ans = 0;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        v.push_back(x);
        s += v[i];
        v[i] = s;
    }
    for(int  i = 0; i < n + 1; ++i){
        if(x >= v[i]){
            ++ans;
        }
    }
    cout << ans << '\n';
	return 0;
}