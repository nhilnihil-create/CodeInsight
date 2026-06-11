#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 20;
vector<ll> seq_a(MAX);
typedef pair<double,double> Point;

void solve(ll target, Point p1, Point p2)
{
    if( target == 0 ) return;
    Point s, t, u;
    double th = M_PI * 60.0 / 180.0; // ラジアンを使うのは常識

    s = make_pair( ( 2.0 * p1.first + 1.0 * p2.first ) / 3.0,
                  ( 2.0 * p1.second + 1.0 * p2.second ) / 3.0 );
    t = make_pair( ( 1.0 * p1.first + 2.0 * p2.first ) / 3.0,
                  ( 1.0 * p1.second + 2.0 * p2.second ) / 3.0 );
    u = make_pair( (t.first - s.first) * cos(th) - (t.second - s.second) * sin(th) + s.first,
                   (t.first - s.first) * sin(th) + (t.second - s.second) * cos(th) + s.second );
    
    solve( target - 1, p1, s );
    printf("%.8f %.8f\n", s.first, s.second);
    solve( target - 1, s, u );
    printf("%.8f %.8f\n", u.first, u.second);
    solve( target - 1, u, t );
    printf("%.8f %.8f\n", t.first, t.second);
    solve( target - 1, t, p2) ;
}

signed main() {
    ll n; cin >> n; 
    Point p1, p2;
    p1 = make_pair(0.0,0.0);
    p2 = make_pair(100.0,0.0);
    printf("%.8f %.8f\n", p1.first, p1.second);
    solve(n, p1, p2);
    printf("%.8f %.8f\n", p2.first, p2.second);
    return 0;
}

