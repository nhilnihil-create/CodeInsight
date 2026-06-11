#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define tc(t)  int t; cin>>t; while(t--)
#define f(n)    for(int i=0;i<n;i++)
#define endl   "\n"
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
     int n;
     cin>>n;
     vector<int>v(n);
 
     f(n)cin>>v[i];
     int k=1;
     int count=0;
     for(int i=0;i<n;i++)
     {
         if(v[i]!=k) count++;
         else k++;
     }
     if (count==n) cout<<"-1"<<endl;
     else 
        cout<<count<<endl;
 
 
}