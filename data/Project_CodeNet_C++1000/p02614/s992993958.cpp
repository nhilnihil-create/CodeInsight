#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define READ(FILE) freopen(FILE,"r",stdin)
#define WRITE(FILE) freopen(FILE,"w",stdout)
#define loop(i,s,e) for(int i=s;i<e;i++)
#define mego fast();
using namespace std;
void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll lcm(ll x, ll y)
{
    return (x*y)/__gcd(x,y);
}
int sum(string s)
{
    int x=0,sz=s.size();
    loop(i,0,sz)x+=(s[i]-'0');
    return x;
}

int main()
{
    mego
    int n,m,k;
   // cout<<(1<<1)<<endl<<(1<<2)<<endl;
   cin>>n>>m>>k;
   char arr[n][m];
   loop(i,0,n)
   loop(j,0,m)
   cin>>arr[i][j];
   int ans=0;
   int p1=1,p2=1;
   loop(i,0,n)p1*=2;
   loop(i,0,m)p2*=2;
   loop(c1,0,p1)
   loop(c2,0,p2)
   {int cur=0;
       loop(i,0,n)
       loop(j,0,m)
       if(arr[i][j]=='#' && !((1<<i & c1)||(1<<j & c2)))cur++;
   ans+=(cur==k);
   }
   cout<<ans;
        return 0;
}

