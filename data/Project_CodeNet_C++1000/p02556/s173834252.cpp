        #include <bits/stdc++.h>

        using namespace std;
        typedef long long ll;
        void __print(int x) {cerr << x;}
        void __print(long x) {cerr << x;}
        void __print(long long x) {cerr << x;}
        void __print(unsigned x) {cerr << x;}
        void __print(unsigned long x) {cerr << x;}
        void __print(unsigned long long x) {cerr << x;}
        void __print(float x) {cerr << x;}
        void __print(double x) {cerr << x;}
        void __print(long double x) {cerr << x;}
        void __print(char x) {cerr << '\'' << x << '\'';}
        void __print(const char *x) {cerr << '\"' << x << '\"';}
        void __print(const string &x) {cerr << '\"' << x << '\"';}
        void __print(bool x) {cerr << (x ? "true" : "false");}

        template<typename T, typename V>
        void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
        template<typename T>
        void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
        void _print() {cerr << "]\n";}
        template <typename T, typename... V>
        void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
        #ifndef ONLINE_JUDGE
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
        #else
        #define debug(x...)
        #endif
        const long long INF  = 1e18;
        int md = 1e9+7;
   
        int main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int n;
            cin>>n;
            vector<pair<int,int>>points(n);
            for(int i=0;i<n;i++)
            {
                int x,y;
                cin>>x>>y;
                points[i].first = x;
                points[i].second = y;
            }

            sort(points.begin(),points.end());
            int minsum = INT_MAX;
            int mindiff = INT_MAX;
            int ans = INT_MIN;
            for(int i=0;i<n;i++)
            {
                int x = points[i].first;
                int y = points[i].second;

                int sum = x + y;
                int diff= x-y;
                if(i>0)
                {
                    ans = max(ans,sum - minsum);
                    ans = max(ans,diff-mindiff);
                }
                minsum = min(minsum,sum);
                mindiff = min(mindiff,diff);
                
            }
            cout<<ans;
            
        }
        //https://www.youtube.com/watch?v=ZQqccia8bVo