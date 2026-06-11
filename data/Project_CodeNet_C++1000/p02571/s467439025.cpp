//invincible M15
//IIT-(ISM)Dhanbad
#include<bits/stdc++.h>
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define pi  3.141592653589793238462643383279
#define ff first
#define ss second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=(int)x; i<y; i++)
#define high_functioning_sociopath  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const unsigned int M = 998244353;
/*------------------------------------- THE GAME IS ON ---------------------------------------------*/
void solve()
{
     string s,t;
     cin>>s>>t;
     int minn=INT_MAX;
     int p=s.size()-t.size();
     int z=t.size();
     for(int i=0;i<=p;i++)
     {
            int ct=0;
            int k=i;
            for(int j=0;j<z;j++)
            {
                   if(s[k]!=t[j])ct++;
                   k++;
            }
            minn=min(ct,minn);
     }
     cout<<minn<<endl;
}
int32_t main()
{
   high_functioning_sociopath
   ll t=1;
   //cin>>t;
   while(t--)
   {
      solve();
   }
}