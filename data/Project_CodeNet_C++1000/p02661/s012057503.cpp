#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000000000001
#define mod 1000000007


using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<int> st(n), en(n);
    for (int i = 0; i < n; i++){
        cin >> st[i] >> en[i];
    }
    sort(st.begin(), st.end());
    sort(en.begin(), en.end());
    if (n % 2 == 1){
        int mn = st[n/2];
        int mx = en[n/2];
        cout << mx-mn+1 << endl;
    } else {
        double mn = ((double)st[n/2-1]+st[n/2])/2;
        double mx = ((double)en[n/2-1]+en[n/2])/2;
        if (mn == mx){
            cout << 1 << endl;
            return 0;
        } else if (mx-mn == 0.5){
            cout << 2 << endl;
            return 0;
        }
        //cout << mn << " " << mx << endl;
        int ans = (ceil(mn) != floor(mn)) + (ceil(mx) != floor(mx));
        //cout << ans << endl;
        mn = ceil(mn);
        mx = floor(mx);
        ans += mx-mn+1;
        ans += mx-mn;
        cout << ans << endl;
    }
    return 0;
}





















