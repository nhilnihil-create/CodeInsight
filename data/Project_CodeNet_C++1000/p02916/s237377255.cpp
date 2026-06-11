
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];
    rep(i,n-1) cin >>c[i];

    int ans=0;
    int prev=-100;
    for(int i=0; i<n; i++){
        ans += b[a[i]-1];
        if(a[i]==prev+1){
            ans += c[prev-1];
        }
        prev = a[i];
    }

    cout << ans << endl;

}