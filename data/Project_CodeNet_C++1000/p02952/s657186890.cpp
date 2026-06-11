#include <bits/stdc++.h>
#define rep(i,x,n) for(int i = x; i < (int)(n); i++)
#define rep_ll(i,x,n) for(ll i = x; i < (ll)(n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long u_ll;
typedef pair<int, int> pair_;
const long double PI = (acos(-1));
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0}; const int dy[] = {0, -1, 0, 1};
ll mod = 1000000007;
int main(){
    int n;
    cin >> n;
    int cnt=0;
    for(int i=1; i<=n; i++){
        int keta=log10(i)+1;
        if(keta%2==1) cnt++;
    }
    cout << cnt;
}