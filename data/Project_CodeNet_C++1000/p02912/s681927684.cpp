/*
 Author:Alokit Kumar
   */
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long 
  int32_t main()
  {
    int n,m,i,j,k,l,s=0;
    cin>>n>>m;
    map<int,int> m1;
    for(i=1;i<=n;i++)
    {
      cin>>k;
      m1[k]++;
    }
    map<int,int>::reverse_iterator it;
    for(i=1;i<=m;i++)
    {
      it=m1.rbegin();
      j=(it->first);
      m1[j/2]++;
      m1[j]--;
      if(m1[j]==0)
       m1.erase(j);
    }
    for(auto it=m1.begin();it!=m1.end();it++)
     {
       j=(it->first),k=(it->second);
       s+=j*k;
     }
     cout<<s;
  }