#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define first    ff
#define second   ss
#define pi       acos(-1.0)
#define test     int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;
int a[28],b[28];

int main()
{      
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
     ll a,b,c,d;
     cin>>a>>b>>c>>d;

     cout<<max(max(a*c,a*d),max(b*c,b*d))<<endl;
      
    
      return 0;
      
 }       
