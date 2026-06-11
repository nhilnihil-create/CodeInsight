#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAX 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define zoom ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define precise cout.precision(8); cout << fixed;
#define seed srand(chrono::steady_clock::now().time_since_epoch().count());
const double PI = acos(-1);
using namespace std;

int main() {


    zoom;    
    int L, R, d; cin >> L >> R >> d;
    int ans = (R / d) - ((L - 1) / d);
    cout << ans;
    return 0;
}