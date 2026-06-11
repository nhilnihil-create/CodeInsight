#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x1) cout<<#x1<<": "<<x1<<endl
#define debug2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl

signed main(){
    int n; cin >> n;
    vector<int> a(n),b(n+1,0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1; i < n+1; i++) {
        if(b[i]>0) cnt += b[i]*(b[i]-1)/2;
    }
    for(int i = 0; i < n; i++) {
        if(b[a[i]]>1) cout << cnt - b[a[i]]*(b[a[i]]-1)/2 + (b[a[i]]-1)*(b[a[i]]-2)/2  << endl;
        else cout << cnt << endl;
    }
    return 0;
}