#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    for ( int i=0; i<n; i++ ) {
        cin >> a[i];
    }
    for ( int i=0; i<k; i++ ) {
        vector<int> b(n+1);
        for ( int i=0; i<n; i++ ) {
            int l=max(0,i-a[i]);
            int r=min(n,i+a[i]+1);
            b[l]++; b[r]--;
        }
        a[0]=b[0];
        for ( int i=1; i<n; i++ ) {
            b[i]+=b[i-1];
            a[i]=b[i];
        }
        bool flag=1;
        for ( int i=0; i<n; i++ ) {
            if ( a[i]!=n ) {
                flag=0;
                break;
            }
        }
        if ( flag ) break;
    }
    for ( int i=0; i<n; i++ ) {
        cout << a[i] << ' ';
    }
    return 0;
}