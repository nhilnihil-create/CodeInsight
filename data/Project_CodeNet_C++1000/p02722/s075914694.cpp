 
//It doesn't matter how slow you go, Unless you don't stop.
#include<iostream>
#include<algorithm>
#include<bitset>
 
#include<cmath>
#include<cstring>
#include<climits>
 
#include<deque>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
 
#include<fstream>
#include<chrono>
using namespace std;
 
typedef long long LL;
typedef pair<LL,LL> p64;
typedef vector<LL> v64;
typedef map<LL,LL> mp64;
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,s,e) for(long long i=s;i<=e;i++)
#define brep(i,s,e) for(long long i=s;i>=e;i--)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define DANGER std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 set<LL> s;
 LL n;
LL cnt=0;
void solve(LL x)
{
    LL dummy = n;
    if(x==1)
    {
        return;
    }
    while(dummy%x==0)
    {
        dummy /= x;
    }
    if(dummy%x==1)
    {
        cnt++;
    }
}
void solve()
{
     cin>>n;
     for(LL i=1;i*i<=n;i++)
     {
         if(n%i==0)
         {
             solve(i);
             s.insert(i);
             if(i*i != n)
             {
                 solve(n/i);
                 s.insert(n/i);
             }
         }
     }
     --n;
     for(LL i=1;i*i<=n;i++)
     {
         if(n%i==0)
         {
             if(s.find(i)==s.end())
             {
                 cnt++;
             }
             if(i*i != n)
             {
                 if(s.find(n/i)==s.end())
                {
                     cnt++;
                }
             }
         }
     }

     cout<<cnt<<endl;
     
         
}
 
int main()
{
    DANGER;
    ofstream out("output.txt");
 
    auto start = chrono::high_resolution_clock::now();
    
    LL t = 1;
    // cin>>t;
    rep(test,1,t)
    {
        solve();
    }
    
    auto stop = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start); 
    // cout << "Time taken by function: " << duration.count() << " milliseconds" << endl;
}