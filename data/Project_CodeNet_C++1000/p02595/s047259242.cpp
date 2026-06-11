#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;

int main() {
    ll n,d;
    cin >> n >> d;
    int cnt = 0;
    rep(i,n){
        ll x,y;
        cin >> x >> y;
        if(x*x+y*y<=d*d) cnt++;
    }
    cout << cnt << endl;
 
	return 0;
}