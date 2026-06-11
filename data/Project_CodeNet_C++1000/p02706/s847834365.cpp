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
#define PI (long double)3.1415926535

int main(){
    FAST
    int n, m; cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        sum += a;
    }
    if(sum > n){
        cout << -1;
        return 0;
    }
    cout << n - sum;
    return 0;
}
