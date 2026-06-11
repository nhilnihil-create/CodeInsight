//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

void start() {
	#ifndef ONLINE_JUDGE 
		freopen("in", "r", stdin); 
		freopen("out", "w", stdout); 
	#endif
}

int n, m;
string s;

int32_t main() {
    IOS;
    start();

    cin >> n >> m >> s;
    set<pair<int,int>> st;
    st.insert({0,0});

    int dp[n+2][2];
    dp[0][0] = 0;
    dp[0][1] = 0;

    for(int i = 1 ; i <= n ; i++) {
        if(s[i] == '1') {
            if(i >= m) {
                st.erase({dp[i - m][0], i - m});
            }
            continue;
        }
        if(!st.size()) {
            return cout << -1, 0;
        }
        auto it  = st.begin();
        dp[i][0] = (*it).first + 1;
        dp[i][1] = (*it).second;
        st.insert({dp[i][0],i});
        if(i>=m) {
            st.erase({dp[i - m][0], i - m});
        }
    }
    int pos = n;
    vector<int> v;
    while(pos != 0) {
        v.push_back(pos - dp[pos][1]);
        pos = dp[pos][1];
    }
    reverse(v.begin(), v.end());
    for(auto i: v)
        cout << i << " ";
}   