#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
typedef long long ll;

int main(){
    int n; cin >> n;
    ll a[n+1] = {0};
    REP(i,1,n+1)cin >> a[i];
    REP(i,1,n+1){
        printf("node %lld: key = %lld, ", i, a[i]);
        if(i != 1)printf("parent key = %lld, ", a[i/2]);
        if(2*i <= n)printf("left key = %lld, ", a[2*i]);
        if(2*i + 1 <= n)printf("right key = %lld, ", a[2*i + 1]);
        cout << endl;
    }
    return 0;
}
