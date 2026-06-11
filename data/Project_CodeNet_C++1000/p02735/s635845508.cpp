#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define int             ll
#define ff              first
#define ss              second
#define pb              emplace_back
#define mpair           make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define sbits(x)      __builtin_popcountll(x)
#define zbits(x)      __builtin_popcountlliltin_ctzll(x)
#define w(t)            int t;cin>>t;while(t--)
#define uset            unordered_set
#define dor(i, a, b)    for(int i =(a);i<=(b);i++)
#define mem(a,val)      memset((a),(val),sizeof((a))); 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
    template <typename Arg1>
     void __f(const char* name,Arg1&& arg1){
        cout<<name<<" : "<<arg1<<std::endl;
     }
     template <typename Arg1, typename... Args>
     void __f(const char* names,Arg1&& arg1,Args&&... args){
        const char* comma = strchr(names+1 ,',');
        cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
     }
#else
#define trace(...)
#endif
/*     
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
*/
double pi = 2.0*acos(0);
void fast(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed<<setprecision(10);}
int max2(int a,int b){ if(a>b) return a;return b;}
int min2(int a,int b){ if(a<b)return a;return b;}
int max3(int a,int b,int c){ return max2(a,max2(b,c));}
int min3(int a,int b,int c){ return min2(a,min2(b,c));}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////



void solve()
{
        int h,w;
        cin>>h>>w;
        string s[h];
        for(int  i  = 0;i<h;i++)
        {
           cin>>s[i];
        }

       int dp[h][w];
        dp[0][0] = (s[0][0]=='#')?1:0;
       for(int  i = 0;i<h;i++)
       {
          for(int  j = 0;j<w;j++)
          {
                if(i==0 && j==0)
                  continue;
                dp[i][j] = 1e9;
                if(j>0)
                  dp[i][j] = min(dp[i][j],(s[i][j-1]=='.' && s[i][j]=='#')+dp[i][j-1]);
                if(i>0)
                  dp[i][j] = min(dp[i][j],(s[i-1][j]=='.' && s[i][j]=='#')+dp[i-1][j]);
          }
       }

       cout<<dp[h-1][w-1]<<endl;  

}

signed main(void)
{
      fast();
      //w(t)
      solve();

}
