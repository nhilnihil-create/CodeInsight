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
    double H, W, x, y; cin >> H >> W >> x >> y;
    double area = H * W;
    int aux = 0;
    if(x + x == H && y + y == W) ++aux;
    cout << fixed << setprecision(9);
    cout << area / 2 << ' ' << aux << '\n';
	return 0;
}