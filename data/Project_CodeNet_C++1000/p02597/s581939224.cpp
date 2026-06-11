#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    string c;
    cin >> c;
    int cntr=0;
    for (int i=0;i<n;i++) {
        if (c[i]=='R') cntr++;
    }
    int cntw_to_cntr=0;
    for (int i=0;i<cntr;i++) {
        if (c[i]=='W') cntw_to_cntr++;
    }
    cout << cntw_to_cntr << endl;
    return 0;
}