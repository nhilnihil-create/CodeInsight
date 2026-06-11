
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    int ans=0;
    for(int i=1; i<n-1; i++){
        if(p[i]<p[i-1] && p[i]>p[i+1]){
            ans ++;
        }
        else if(p[i]>p[i-1] && p[i]<p[i+1]){
            ans ++;
        }
    }
    cout << ans << endl;

}