#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n], b[n], c[n-1];
    REP(i, n){
        cin >> a[i];
        a[i]--;
    }
    REP(i, n) cin >> b[i];
    REP(i, n-1) cin >> c[i];

    int result = b[a[0]];

    for(int i=1; i<n; i++){
        result += b[a[i]];
        if(a[i]-a[i-1]==1){
            result += c[a[i-1]];
        }
    }
    cout << result << endl;
    return 0;
}