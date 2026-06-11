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
        ll powmod(ll x,ll y){
            ll res=1;
            for(ll i=0;i<y;i++){
                res=res*x%md;
            }
            return res;
        }
        int nCrModpDP(int n, int r, int p) 
    { 
        // The array C is going to store last row of 
        // pascal triangle at the end. And last entry 
        // of last row is nCr 
        int C[r+1]; 
        memset(C, 0, sizeof(C)); 
    
        C[0] = 1; // Top row of Pascal Triangle 
    
        // One by constructs remaining rows of Pascal 
        // Triangle from top to bottom 
        for (int i = 1; i <= n; i++) 
        { 
            // Fill entries of current row using previous 
            // row values 
            for (int j = min(i, r); j > 0; j--) 
    
                // nCj = (n-1)Cj + (n-1)C(j-1); 
                C[j] = (C[j] + C[j-1])%p; 
        } 
        return C[r]; 
    } 
    
    // Lucas Theorem based function that returns nCr % p 
    // This function works like decimal to binary conversion 
    // recursive function.  First we compute last digits of 
    // n and r in base p, then recur for remaining digits 
    int nCrModpLucas(int n, int r, int p) 
    { 
    // Base case 
    if (r==0) 
        return 1; 
    
    // Compute last digits of n and r in base p 
    int ni = n%p, ri = r%p; 
    
    // Compute result for last digits computed above, and 
    // for remaining digits.  Multiply the two results and 
    // compute the result of multiplication in modulo p. 
    return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r 
            nCrModpDP(ni, ri, p)) % p;  // Remaining digits 
    }
        int main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            long long s ;
            cin>>s;
            long long ans =0LL;
            if(s<=2)
            {
                cout<<"0\n";
                exit(0);
            }
            for(int t=2;s-3*t>=0;t++)
            {
                long long ret = nCrModpLucas(s-2*t-1, t-1, md);
                ans = (ans + ret)%md;
            }
            cout<<(ans + 1)%md;
        }
        //https://www.youtube.com/watch?v=ZQqccia8bVo