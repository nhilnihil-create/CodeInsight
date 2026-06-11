 
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define fill(a,val) memset(a,val,sizeof(a))
#define REP(i,a,b) for (auto i = a; i != b; i++)
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define pb push_back
#define SQ(a) (a)*(a)
 
const int N = 10005;
using namespace std;
 
int main()
{
    std::ios::sync_with_stdio(false);
    //ll p = 1000000007; 
    
    int T = 1;
    //cin>>T;
    // cin.ignore(); must be there when using getline(cin, s)
    while(T--)
    {
          int n,m;
          cin>>n>>m;
          vi a(n);
          ll sum = 0;
          REP(i,0,n)
          {
            cin>>a[i];
            sum+=a[i];
          }
          sort(a.rbegin(),a.rend());
          float k = (float)sum/4;
          k = k/m;
          if(a[m-1] < k)
            cout<<"No";
          else
            cout<<"Yes";
          
    }
    return 0;
}

 