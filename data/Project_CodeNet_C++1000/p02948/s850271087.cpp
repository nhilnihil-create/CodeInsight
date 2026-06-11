        #include <bits/stdc++.h>
        #define MAXN 200100
        #define pii pair<int,int>
        #define ff first
        #define ss second
        #define ll long long
        #define in_range(x, y, n) (x >= 0 and x<n and y >=0 and y<n)
        using namespace std;
        const ll mod = 1e9 + 7;


        int main (){
            ios_base::sync_with_stdio(false);
            int n, m;

            cin >> n >> m;

            vector<int> v[MAXN];
            for (int i=0; i<n; i++){
                int a, b;
                cin >> a >> b;
                v[a].push_back(b);
            }

            ll ans = 0;

            multiset<int> st;
            for (int i=1; i<=m; i++){
                for (auto x: v[i]) st.insert(x);
                if (st.empty()) continue;

                ans += *prev(st.end());
                st.erase(prev(st.end()));
            }

            cout << ans << endl;
            return 0;
        }