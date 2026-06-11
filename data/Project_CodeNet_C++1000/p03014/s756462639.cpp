#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
//krishrawat
 
 
//----------------------------MACROS-------------------------------------------------
#define pb insert//                                                                 |
#define eb emplace_back//                                                           |
#define ff first//                                                                  |
#define ss second//                                                                 |
typedef long long int ll;//                                                         |
typedef long double ld;//                                                           |
#define all(a) a.begin(), a.end()//                                                 |
#define show(x) cerr << #x << " is " << x << "\n"//                                 |
#define show2(x, y) cerr << #x << " " << #y << " " << x << " " << y << "\n"//       |
typedef vector<ll> vl;//                                                            |
typedef vector<vl> vvl;//                                                           |
typedef pair<ll, ll> pp;//                                                          |
typedef vector<pp> vp;//                                                            |
typedef map<pp, ll> ipi;//                                                          |
typedef map<pp, char> ipc;//                                                        |
typedef map<ll, ll> ii;//                                                           |
typedef set<ll> sl;//                                                               |
typedef multiset<ll> msl;//                                                         |
typedef map<char, ll> ci;//                                                         |
typedef set<pair<ll, ll>> sp;//                                                     |
const ll mod = 1e9 + 7;//                                                           |
const ll N = 2e3 + 1;//                                                             |
//----------------------------------------------------------------------------------

//global declarations
char grp[N][N]={0};
ll val[4][N][N]={0};
ll n,m;

//solution
void solve()
{   
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grp[i][j];
            if(grp[i][j]=='.'){
                for(int k=0;k<4;k++){
                    val[k][i][j]=1;
                }
            }
        }
    }
    
    ll ans=0;
    
    //count no of number of ones consecutively 
    
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(grp[i][j]=='.') val[0][i][j]+=val[0][i][j-1];  //from left to right
            if(grp[i][m-1-j]=='.') val[1][i][m-1-j]+=val[1][i][m-j]; // from right to left
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(grp[j][i]=='.') val[2][j][i]+=val[2][j-1][i]; //from top to down
            if(grp[n-1-j][i]=='.') val[3][n-1-j][i]+=val[3][n-j][i]; // from down to top
        }
    }
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll tmp=0;
            for(int k=0;k<4;k++){
                tmp+=val[k][i][j];
            }
            tmp-=3;
            ans=max(ans,tmp);
        }
    }
    cout<<ans<<"\n";
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll t; t=1;
    //cin>>t;
    while(t--) solve(); return 0;
}