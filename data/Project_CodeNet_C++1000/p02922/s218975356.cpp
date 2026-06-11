#include<bits/stdc++.h> 
#include<random> 
#define int long long 
#define pp pair<int,int> 
#define ss second 
#define ff first 
#define pb push_back 
#define mod 1000000007 
using namespace std; 
void fastio() 
{ 
    #ifndef ONLINE_JUDGE 
    freopen("INPUT.txt","r",stdin); 
    freopen("OUTPUT.txt","w",stdout); 
    #endif 
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL) ; 
    cout.tie(NULL); 
}

signed main() 
{ 
    fastio(); 
    int t=1;
  //  cin>>t;
    while(t--)
    {
       
       int c=1,d=0;
       int a,b;
       cin>>a>>b;
       while(c<b)
       {
           c+=a;
           c--;
           d++;
       }
       cout<<d;
    }
}
