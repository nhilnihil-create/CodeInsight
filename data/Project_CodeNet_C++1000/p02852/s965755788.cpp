#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    stack<ll> st;
    ll now = n;
    while(now){
        for(i = m;i >= 1;--i){
            if(now-i < 0) continue;
            else if(s.at(now-i) == '0'){
                st.push(i);
                now -= i;
                break;
            }
        }
        if(i == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    while(!st.empty()){
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}