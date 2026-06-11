#include<bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define endl '\n'
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// head
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    if(m % 2 == 0) {
        // split the tourneys in the middle
        int low1 = 1;
        int high1 = m + 1;
        for(int i = 0; i < m / 2; i++) {
            cout << low1 << " " << high1 << endl;
            low1++;
            high1--;
        }
        low1 = m + 2;
        high1 = 2*m+1;
        for(int i = 0; i < m / 2; i++) {
            cout << low1 << " " << high1 << endl;
            low1++;
            high1--;
        }
    } else {
        int low1 = 1;
        int high1 = m;
        for(int i = 0; i < m / 2; i++) {
            cout << low1 << " " << high1 << endl;
            low1++;
            high1--;
        }
        low1 = m + 1;
        high1 = 2*m+1; 
        for(int i = 0; i < (m + 1) / 2; i++) {
            cout << low1 << " " << high1 << endl;
            low1++;
            high1--;
        }
    }
    return 0;
}