
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<double> v(n);
    rep(i,n) cin >> v[i];
    //小さい順に並び替えて順番に処理する
    sort(all(v));
    double ans=0;
    for(int i=0; i<n-1; i++){
        ans = (v[i]+v[i+1])/2;
        v[i+1] = ans;
    }
    cout   << ans << endl;


}