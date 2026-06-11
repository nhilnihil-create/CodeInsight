#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    

    int n;
    cin>>n;
    int a[1<<n];
    int m = 1<<n;
    multiset<int> rem,st;
    for(int i=0;i<m;i++){
        cin>>a[i];
        rem.insert(a[i]);
    }
    auto k = rem.end();
    k--;
    cerr<<*k<<endl;
    st.insert(*k);
    rem.erase(k);
    // for(auto i:rem) cerr<<i<<endl;
    rem.insert(1e9);
    rem.insert(-1);
    for(int i=0;i<n;i++){
        multiset<int> s = st;
        for(auto j:s){
            auto k = rem.lower_bound(j);
            k--;
            // cerr << j << " " << *k << endl;
            if(*k == -1){
                cout << "No" << endl;
                return 0;
            }
            st.insert(*k);
            // cerr << *k << " ";
            // k++;
            // cerr<<*k<<endl; 
            rem.erase(k);
            // for(auto i:rem) cerr<<i<<endl;
        }
    }
    cout << "Yes" << endl;

    
}