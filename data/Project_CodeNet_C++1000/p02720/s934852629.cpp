#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll k;
queue<ll>st;

void solve(){
    cin >> k;
    for(int i=1;i<10LL;++i)
        st.push(i);
    for(int i=0;i<k;++i) {
        ll f = st.front();
        st.pop();
        if(i == k-1) 
            cout << f << "\n";
        if(f%10LL!=0)
            st.push(10LL*f + (f%10LL) - 1);
        st.push(10LL*f + (f%10LL));
        if(f%10LL!=9)
            st.push(10LL*f + (f%10LL) + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--)
        solve();
    return  0;
}
