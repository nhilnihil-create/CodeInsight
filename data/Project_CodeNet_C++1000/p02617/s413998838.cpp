        #include <bits/stdc++.h>
        using namespace std;
        #define tani_nachi_ke  ios_base::sync_with_stdio(false); cin.tie(NULL);
        #define M_PI 3.14159265358979323846
        #define data data_
        #define ff first
        #define ss second
        #define pb push_back
        #define ld long double
        #define int long long
        #define print(t) cout << "Case #" << t << ": ";
        int32_t main()
        {
            tani_nachi_ke  
            
            

            int ans = 0;
            int n;
            cin >> n;
            for(int i = 0; i < n-1; i++)
            {
                int u,v;
                cin >> u >> v;
                if(u > v)
                    swap(u,v);
                ans -= u * (n - v + 1);
            }
            for(int i = 1; i <= n; i++)
            {
                ans += i*(n-i+1);
            }
            cout << ans << '\n';




           return 0;
        }
          