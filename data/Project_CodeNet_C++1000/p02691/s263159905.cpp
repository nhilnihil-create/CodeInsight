#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

int n;
map<int, int> m;
ll ans = 0;

int main(){
    cin >> n;
    Rep(i, n){
        int a;
        cin >> a;
        m[i+a]++;
        ans += m[i-a];
    }
    cout << ans << endl;
    return 0;
}