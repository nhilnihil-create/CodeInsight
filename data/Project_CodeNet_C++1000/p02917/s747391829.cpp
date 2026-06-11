#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> b(n-1); 
    rep(i,n-1) cin >> b[i];
    vector<int> a(n);
    a[0] = b[0]; a[n-1] = b[n-2];
    int sum = a[0] + a[n-1];
    for(int i=0; i<n-2; i++){
        a[i+1] = min(b[i],b[i+1]);
        sum+=a[i+1];
    }
    cout << sum << endl;
    return 0;
}