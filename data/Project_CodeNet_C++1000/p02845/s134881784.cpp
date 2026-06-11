#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    multiset<int> st = {0, 0, 0};

    int mod = 1e9 + 7;
    int count = 1;
    for(int i=0; i<n; i++){
        int num = st.count(a[i]);
        count = (count * num) % mod;
        if(num != 0){
            auto itr = st.find(a[i]);
            st.insert(*itr + 1);
            st.erase(itr);
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    cout << count << endl;
    return 0;
}