#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i=0; i<m; i++) {
        cin >> a[i];
        n -= a[i];
    }

    if( n < 0) n = -1;

    cout << n << endl;
}