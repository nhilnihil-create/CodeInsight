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
    ll x,k,d;
    cin >> x >> k >> d;
    ll num = abs(x)/d;
    if(k < num){
        if(x > 0) cout << abs(x-k*d) << endl;
        else cout << abs(x+k*d) << endl;
    }else{
        ll z = k-num;
        if(x > 0){
            if(z%2 == 0) cout << abs(x%d) << endl;
            else cout << abs(x%d-d) << endl;
        }else{
            if(z%2 == 0) cout << abs(x%d) << endl;
            else cout << abs(x%d+d) << endl;
        }
    }
	return 0;
}