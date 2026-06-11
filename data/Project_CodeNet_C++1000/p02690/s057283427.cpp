#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))
#define F first
#define S second
#define int ll


int32_t main(){
    FAST
    int x; cin >> x;
    for(int i = -1e3; i <= 1e3; i++){
        for(int j = -1e3; j <= 1e3; j++){
            if(i*i*i*i*i - j*j*j*j*j == x){
                cout << i << " " << j;
                return 0;
            }
        }
    }
    return 0;
}
