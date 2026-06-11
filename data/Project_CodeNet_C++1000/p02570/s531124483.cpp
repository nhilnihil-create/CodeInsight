#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 1003;
int n, m;
int a[SZ];

int main() {
    setIO();
    // for (int i = 1; i <= n; i++) {
    //     cin>>a[i];
    // }
    int d, t, s;
    cin>>d>>t>>s;
    cout<<((d<=s*t)?"Yes":"No")<<endl;
    
    return 0;
}
