/*
 Author:Alokit Kumar
   */
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long 
  int32_t main()
  {
    int n,m,i,j,k,l,q,s=0;
   string s1;
   cin>>s1;
   n=s1.size();bool hi=true;
   for(i=0;i<n;i++)
   {
     if(i%2==0)
     {
       if(s1[i]=='L')
       {
         hi=false;
         break;
       }
     }
     else
     {
       if(s1[i]=='R')
       {
         hi=false;
         break;
       }
     }
   }
   if(hi) cout<<"Yes";
   else cout<<"No";
  }