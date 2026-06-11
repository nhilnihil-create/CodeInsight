#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less  
using namespace         std;
#define                 int long long
#define                 pb push_back
#define                 mp make_pair
#define st(arr,a)       memset(arr,a,sizeof arr)
#define                 nl cout<<'\n'
#define bitcount(x)     __builtin_popcountll(x)
const int MOD = 998244353;
#define forn(i,a,b)     for(int i=a;i<=b;i++)
#define rfor(i,a,b)     for(int i=a;i>=b;i--)
#define all(x)          x.begin() , x.end()
#define pi pair<int,int>
#define X first
#define Y second
#define sz(A) (int)A.size()
#define N 3159
#define  vi vector<int>
#define  v  vector
#define die exit(0)
#define alln(arr) arr+1 , arr+1+n
using namespace __gnu_pbds;  
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update> oset; 

// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).

#define in input_int()
#define ins input_string()
int input_int(){int a;cin>>a;return a;}
string input_string(){string s;cin>>s;return s;}
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};



int n,m,k,a,b,c,d,x,y,arr[N];
string s;

int dp[N][N];

int get(int idx,int sum)
{
    if(sum>k)return 0;
    if(idx == n+1)
    {
        if(sum==k)return 1;
        return 0;
    }
    int&ans=dp[idx][sum];
    if(ans!=-1)return ans;
    
    ans=get(idx+1,sum+arr[idx]);
    ans%=MOD;
    ans+=(2*get(idx+1,sum))%MOD;
    ans%=MOD;
    return ans;
}

void solve()
{
    st(dp,-1);
    cin>>n>>k;
    forn(i,1,n)cin>>arr[i];
    cout<<get(1,0);

}


signed main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t = 1;
    //cin>>t;
    forn(i,1,t)
    {
        solve();
        nl;
    }



    return 0;

}
//       clang++ c.cpp ; ./a.out < a.txt ;  