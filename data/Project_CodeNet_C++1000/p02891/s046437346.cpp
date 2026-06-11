#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define pb push_back
#define vec vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define foo(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define deb(x) cout << #x << " --> " << x << endl;
#define deb1a(v) cout << #v << "--->" << endl; for (auto it : v)  cout << it << " "; cout << endl;
#define deb2a(v) cout << #v << "--->" << endl;for (auto it:v){for(auto it1 : it){cout << it1 << " ";}cout<< endl;}
#define deb3a(v) cout << #v << "-->" << endl; for(auto it:v){cout << it.fi << " " << it.se << endl;}
#define mod 29996224275833
#define so(v) sort(v.begin(),v.end())
#define fi first
#define se second
#define db1(x) cout<<#x<<"="<<x<<endl
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl
int power(int x, unsigned int y, int p){ int res = 1;x = x % p;while (y > 0)  { if (y & 1)res = (res*x) % p;y = y>>1;  x = (x*x)% p;} return res;}
// int mI(int a, int m)  {return power(a, m - 2, m);}
// vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{1,1},{1,-1},{-1,1},{-1,-1}};

string s;
int n ;
int k;
int dp[101][28][28];
int fun(int i,int last,int fi){
    //db3(i, last, fi);
    if(i>=n)
        return 0;
    if(i==n-1){
        if(s[i]-'a'==last)
            return k;
        else if(s[i]-'a'==fi)
            return k - 1;
        else
            return 0;
    }
    if(dp[i][last][fi]!=-1)
        return dp[i][last][fi];
    int ans = 1e15;
    fo(j, 26)
    {
        if (j != last)
        {
            if (i == 0)
                fi = j;
            if (s[i] - 'a' == j)
                ans = min(ans, fun(i + 1, j, fi));
            else
                ans = min(ans, k + fun(i + 1, j, fi));
        }
    }
    return dp[i][last][first]=ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    cin >> k;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int g = 0;
    foo(i,1,n){
        if(s[i]!=s[i-1]){
            //db1(i);
            g = 1;
        }
    }
    if(g==0){
        //deb(n);
        cout << (n*k)/2;
    }
    else
        cout << fun(0, 27, 0);

}
    
