#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define FT() int t; scanf("%d",&t); while(t--)
#define pb push_back
#define nl printf("\n")
#define fi(i,start,end) for(int i=start; i < (int)end ; ++i)
#define ip(n)   scanf("%d",&n)
#define mz(a)   memset(a,0,sizeof(a))
#define inpArr(A,n) fi(i,0,n)   ip(A[i]);
#define print(a)  for(auto i : a)   cout<<i<<" "; nl;
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
ll max(ll a,ll b)   {return a>b?a:b;}
ll min(ll a,ll b)   {return a<b?a:b;}

int main() {
  
    //std::cout << std::fixed;
    //std::cout << std::setprecision(6);
    Fastio;
    int testcase = 1;
    //cin>>testcase;
    while(testcase--)
    {
        int n,x,t;
        cin>>n>>x>>t;
        ll s = (n/x + bool(n%x))*t;
        cout<<s;
    }

    
    return 0;
}