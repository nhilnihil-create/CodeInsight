#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;
 
template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)
 
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;
  

int main() {
    int X, Y; cin >> X >> Y;
    
    int res = 0;
    switch (X) {
    case 1:
        res += 300000;
        break;
    case 2:
        res += 200000;
        break;
    case 3:
        res += 100000;
    default:
        break;
    }
    switch (Y) {
    case 1:
        res += 300000;
        break;
    case 2:
        res += 200000;
        break;
    case 3:
        res += 100000;
    default:
        break;
    }
    if (X == 1 && Y == 1) res += 400000;

    cout << res << endl;
}
