#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    set<int> st;
    rep(i,n){
        int a;
        cin >> a;
        st.insert(a);
    }
    if(st.size()!=n){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
    return 0;
}