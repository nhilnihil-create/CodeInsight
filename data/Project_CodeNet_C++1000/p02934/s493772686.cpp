#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define ALL(v) ((v).begin(),(v).end())
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    REP(i,n) cin >> a[i];

    double val=0.0;
    REP(i,n){
        val += 1.0 / a[i];
    }

    cout << 1.0/val << endl;
    return 0;
}