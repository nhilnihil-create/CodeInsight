

#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define MOD ll(1000000007)
#define debug(x) cout << '[' << #x << " is: " << x << "] " <<endl;
#define decimalpoint cout << std::fixed << setprecision(5)


void solve(){
	long long n , x , t;
	cin >> n >> x >> t;

	cout << (long long)(ceil(n*1.0/x) * t) << endl;

}



int main()
{
    FAST;
    int t;
   	t = 1;

    while(t--){
        solve();
    }
    return 0;
}
