#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// #define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

int main() {
    int n;
    string s; 
    cin >> n >> s;
    int left = 0, right = n - 1;
    int ans = 0;
    while(left <= right){
        if(s[left] == 'W'){
            while(right >= 0){
                if(s[right] != 'R') {
                    right--;
                } else {
                    break;
                }
            }
            if(right < left) break;
            ans++;
            right--;
        }
        left++;
    }
    cout << ans << endl;
    return 0;
}