#include <bits/stdc++.h>
 
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
 
constexpr int INF = 1e9;
constexpr int MOD = 1e9+7;

ll x10[1000010] = {1};

int main() {
    ll k;
    cin >> k;
    for(int i = 1; i < 1000010; i++){
        (x10[i] = x10[i-1]*10)%=k;
    }
    ll sum = 0;
    for(int i = 0; i < 1000010; i++){
        (sum += 7*x10[i]) %= k;
        if(sum%k == 0){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
	return 0;
}