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
    int m,n,ans=0;
    cin >> n >> m;
    ll a[n];
    double sum;

    for(int i=0;i<n;i++){
        cin >> a[i];
        sum = sum + a[i];
    }
    
    for(int i=0;i<n;i++){
        if(a[i] >= sum/(4*m))ans++;
    }

    if(ans >= m)cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;

}
