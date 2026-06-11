#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using p = pair<int,int>;
static const long long INF = 1000000007;

int main(){
    long long min = INF;
    int ans = 0;
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n) cin >> vec[i];
    rep(i,n){
        if (min >= vec[i]){
            ans ++;
            min = vec[i];
        }
    
    }
    cout << ans << endl;
}