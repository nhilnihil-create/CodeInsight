#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mx = 10000007;
using pii = pair<ll, ll>;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
#define ull unsigned long long
#define    ss   second
#define    ff   first
#define    pb   push_back
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))

///--------------Graph Moves--------------------------------------
///const ll fx[] = {+1,-1,+0,+0};
///const ll fy[] = {+0,+0,+1,-1};
///const ll fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const ll fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const ll fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const ll fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

#define FIO ios_base::sync_with_stdio(false);  cin.tie(NULL);


int main() {
    FIO;

    ll n; cin >> n;
    for(ll i = 1; i <= 9; i++) {
        for(ll j = 1; j <= 9; j++) {
            if((i * j) == n) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}