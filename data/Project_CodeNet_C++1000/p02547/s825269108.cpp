#include<bits/stdc++.h>
 
using namespace std;
 
 
#define int long long
 
void solve()
{
   int n;  cin>>n;
   int cnt=0;
   int a[n][2];
   for(int i=0;i<n;i++)cin>>a[i][0]>>a[i][1];
   for(int i=2;i<n;i++)
   {
       if(a[i-2][0]==a[i-2][1]&&a[i-1][0]==a[i-1][1]&&a[i][0]==a[i][1])
       {
           cout<<"Yes"<<endl;
           return ;
       }
   }
    cout<<"No"<<endl;
    return ;
}


 
 
 signed main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    
    
    int T; 
    T=1;
    //cin>>T;
    while(T--)
    {
          solve();
    }
    
    
        return 0;
	
}