
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];
    sort(all(d));
    int len = d.size();

    int ans;
    if(len%2==0){
        ans = d[(len/2)] - d[(len/2)-1];
    }
    else{
        ans = d[(len/2)+1] - d[(len/2)];
    }
    cout << ans << endl;
}