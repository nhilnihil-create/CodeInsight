/*
 Author:Alokit Kumar
   */
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long 
  int32_t main()
  {
    int n,m,i,j,k,l,q,s=0;
    cin>>n>>k>>q;
    map<int,int> m1;
    for(i=1;i<=q;i++)
    {
      cin>>l;
      m1[l]++;
    }
   for(i=1;i<=n;i++)
   {
     j=m1[i];
     j=q-j;
     if((k-j)<=0)
      cout<<"No\n";
     else
      cout<<"Yes\n";
   }
  }