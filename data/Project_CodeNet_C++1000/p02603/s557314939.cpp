#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    REP(i,n){
        cin >> a[i];
    }
    ll kabu = 0;
    ll kane = 1000;
    REP(i,n-1){
        if(a[i]<a[i+1]){
            kabu = kane/a[i];
            kane += kabu*(a[i+1]-a[i]);
        }
    }
    cout << kane << endl;
}