    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/detail/standard_policies.hpp>
    using namespace std;
    using namespace __gnu_pbds;
    #define ll long long
    #define int long long
    #define pb push_back
    #define For(i,n) for(ll  i=0;i<n;i++)
    #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) ;clock_t clk = clock();
    #define f(a,b,c) for(ll a=b;a<c;a++)
    #define mod   998244353
    #define ld long double
    #define read(t) ll t;cin>>t;
    #define all(x) x.begin(),x.end()
    #define fi first
    #define se second
    #define endl "\n"
    #define pii pair<ll,ll>
    #define what_is(x) cerr << #x << " is " << x << endl;
    #define time cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    const double pi=3.14159265358979323846264;
    typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
    typedef tree<long long,null_type,greater<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set1;

/**********************************************************************************************************************/
string longestRepeatedSubstring(string str) 
{ 
    int n = str.length(); 
    int LCSRe[n+1][n+1]; 
  
    // Setting all to 0 
    memset(LCSRe, 0, sizeof(LCSRe)); 
  
    string res; // To store result 
    int res_length  = 0; // To store length of result 
  
    // building table in bottom-up manner 
    int i, index = 0; 
    for (i=1; i<=n; i++) 
    { 
        for (int j=i+1; j<=n; j++) 
        { 
            // (j-i) > LCSRe[i-1][j-1] to remove 
            // overlapping 
            if (str[i-1] == str[j-1] && 
                LCSRe[i-1][j-1] < (j - i)) 
            { 
                LCSRe[i][j] = LCSRe[i-1][j-1] + 1; 
  
                // updating maximum length of the 
                // substring and updating the finishing 
                // index of the suffix 
                if (LCSRe[i][j] > res_length) 
                { 
                    res_length = LCSRe[i][j]; 
                    index = max(i, index); 
                } 
            } 
            else
                LCSRe[i][j] = 0; 
        } 
    } 
  
    // If we have non-empty result, then insert all 
    // characters from first character to last 
    // character of string 
    if (res_length > 0) 
        for (i = index - res_length + 1; i <= index; i++) 
            res.push_back(str[i-1]); 
  
    return res; 
} 
signed main()/*Check flow...question galat mat padhna */
{
    fast;   
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string x=longestRepeatedSubstring(s);
    cout<<x.length()<<endl;
}      