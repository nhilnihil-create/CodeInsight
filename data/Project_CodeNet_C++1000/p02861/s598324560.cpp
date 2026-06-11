#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main(void)
{
    ll n, pat_num = 1;
    long double distance_sum = 0;
    cin >> n;
    vector<ll> x(n), y(n), p(0);
    for(ll i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i);
        p.push_back(i);
        pat_num *= (i + 1);
    }

    do {
        for(ll i = 0; i < n - 1; i++) {
            distance_sum += sqrt( ( x.at(p.at(i + 1)) - x.at(p.at(i)) ) * ( x.at(p.at(i + 1)) - x.at(p.at(i)) ) + ( y.at(p.at(i + 1)) - y.at(p.at(i)) ) * ( y.at(p.at(i + 1)) - y.at(p.at(i)) ) );
        }
    } while ( next_permutation(p.begin(), p.end()) );

    cout << fixed << setprecision(10) << distance_sum / pat_num;

    return 0;
}