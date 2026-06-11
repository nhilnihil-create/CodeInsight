#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main(){
    int n,k;
    cin >> n >>k;
    bool ok[n];
    rep(i,n){
        ok[i]=false;
    }

    for(int i=0;i<k;i++){
        int d;
        cin >> d;
        int a[d];
        rep(i,d){
            cin >> a[i];
            ok[a[i]-1]=true;
        }
    }

    int ans=0;
    rep(i,n){
        if(!ok[i])ans++;
    }

    cout << ans << endl;
    return 0;

}
