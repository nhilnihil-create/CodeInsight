#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
///find_by_order, order_of_key

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main()
{
    #ifdef ljuba
    auto pocetakChronoSata123 = high_resolution_clock::now();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);       
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;

    ll res = 0;
    for(ll i = 2; i * i <= n; ++i)
    {
        ll br = 0;
        while(n % i == 0)
        {
            n /= i;
            ++br;
        }

        for(int i = 1; ; ++i)
        {
            if(br - i >= 0)
            {
                br -= i;
                ++res;
            }
            else
            {
                break;
            }
        }
    }

    if(n > 1)
    {
        res += 1;
    }

    cout << res << '\n';
    
    #ifdef ljuba
    auto krajChronoSata123 = high_resolution_clock::now();
    auto trajanje = duration_cast<microseconds>(krajChronoSata123 - pocetakChronoSata123);
    cout << "----------------------------------------------------\n";
    cout << "Vreme u milisekundama: " << (ld)trajanje.count() / 1000.00 << '\n';
    #endif
    return 0;
}