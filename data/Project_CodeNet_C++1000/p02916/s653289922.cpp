/*
 Author:Alokit Kumar
   */
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long 
  int32_t main()
  {
    int n,i,j,k,l;
    cin>>n;
    int a[n+1],b[n+1],c[n];
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++) cin>>b[i];
    for(i=1;i<n;i++) cin>>c[i];
    int s=b[a[1]];
    for(i=2;i<=n;i++)
    {
      s+=b[a[i]];
      if((a[i]-1)==a[i-1])
       s+=c[a[i-1]];
    }
    cout<<s;
  }